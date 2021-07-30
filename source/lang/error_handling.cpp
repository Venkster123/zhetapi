#include <cstdio>

#include "../../engine/engine.hpp"
#include "../../engine/lang/error_handling.hpp"

namespace zhetapi {

static const size_t threshold = 3;

size_t levenshtein(const std::string &a, const std::string &b)
{
	size_t rows = a.length() + 1;
	size_t cols = b.length() + 1;

	// Make the matrix
	Matrix <size_t> mat(rows, cols,
		[&](size_t i, size_t j) -> size_t {
			if (std::min(i, j)) {
				bool neq = (a[i - 1] != b[j - 1]);
				return std::min(
					mat[i - 1][j] + 1,
					std::min(
						mat[i][j - 1] + 1,
						mat[i - 1][j - 1] + neq
					)
				);
			}

			return std::max(i, j);
		}
	);

	return mat[rows - 1][cols - 1];
}

Args symbol_suggestions(const std::string &symbol, const Args &choices)
{
	Args valid;

	for (const std::string &str : choices) {
		if (levenshtein(str, symbol) < threshold)
			valid.push_back(str);
	}

	return valid;
}

// Enable for tracking symbol errors
// #define SYM_ERR_THROW
void symbol_error_msg(const std::string &symbol, const std::string &loc, Engine *context)
{
	// TODO: add a function for classifying the error
	// TODO: lines too long
	if (loc.empty()) {
		std::fprintf(stderr, "Error: The symbol \"%s\" has not been defined yet.\n",
				symbol.c_str());
	} else {
		std::fprintf(stderr, "Error: The symbol \"%s\" has not been defined yet (from \"%s\").\n",
				symbol.c_str(), loc.c_str());
	}
	
	Args suggs = symbol_suggestions(symbol, context->symbol_list());

	size_t n = suggs.size();
	if (n) {
		std::fprintf(stderr, "Suggested symbols: {\n");

		for (size_t i = 0; i < n; i++) {
			std::fprintf(stderr, "\t%s%s\n", suggs[i].c_str(),
					(i < n - 1) ? "," : "");
		}
		
		std::fprintf(stderr, "}\n");
	}

#ifdef SYM_ERR_THROW

	throw std::runtime_error("Throwing from sym err...");

#endif
}

}
