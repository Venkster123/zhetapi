#ifndef PLOT_H_
#define PLOT_H_

// C/C++ headers
#include <map>
#include <thread>
#include <vector>

// Engine headers
#include "vector.hpp"
#include "fixed_vector.hpp"

// Graphics headers
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>

namespace zhetapi {

// TODO: add distinct coloring
// TODO: replace with dearimgui

/**
 * @brief A canvas that be used to graph functions, plot points, etc.
 */
class Plot {
public:
	using FunctionType = std::function <double (double)>;
	using LGraph = std::vector <Vec2d>;

	// Public structs
	struct Point {
		// Change to Vec2f
		Vector <double>		coords;
		sf::CircleShape		circle;
		// TODO: add custom shape
	};

	struct LineGraph {
		std::vector <Point>	points;
		sf::VertexArray		va;
	};

	struct Curve {
		FunctionType 		ftn;
		sf::VertexArray		va;
	};
private:
	std::string			_name;

	unsigned int			_width = def_width;
	unsigned int			_height = def_height;

	std::thread *			_wman = nullptr;

	std::vector <Point>		_points;
	std::vector <LineGraph>		_lcurves;
	std::vector <Curve>		_curves;

	// Coordinate axes
	struct {
		// Make as arrays next time
		sf::VertexArray x;
		sf::VertexArray y;

		sf::ConvexShape xleft;
		sf::ConvexShape xright;
		sf::ConvexShape yup;
		sf::ConvexShape ydown;

		sf::Color color;
		sf::Font font;

		double xmin;
		double xmax;

		double ymin;
		double ymax;

		sf::Text xtext;
		sf::Text ytext;
	} _axes;

	// Origin
	Vector <float>			_origin;

	sf::ContextSettings		_glsettings;
	sf::RenderWindow		_win;

	bool				_display = false;

	bool out_of_bounds() const;
public:
	Plot(const std::string & = "Plot #" + std::to_string(def_plot_num));

	void plot(const Vector <double> &);
	void plot(const FunctionType &);

	void zoom(double);

	void show();
	void close();

	void run();

	void init_axes();

	void redraw();

	sf::Vector2f true_coords(const Vector <double> &);

	static double zoom_factor;
	static size_t def_width;
	static size_t def_height;
	static size_t def_aa_level;
	static size_t def_plot_num;
	static sf::Color def_axis_col;
};

}

#endif
