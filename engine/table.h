#ifndef TABLE_H_
#define TABLE_H_

#include "node.h"
#include "functor.h"
#include "variable.h"

template <class T>
class functor;

template <class T>
class variable;

template <class T>
class table {
public:
	using var = variable <T>;
	using ftr = functor <T>;
	
	struct __var_node {
		var val;
		__var_node *left;
		__var_node *right;
	};

	struct __ftr_node {
		ftr val;
		__ftr_node *left;
		__ftr_node *right;
	};
private:
	__var_node *vtree;
	__ftr_node *ftree;

	std::size_t vtree_size;
	std::size_t ftree_size;
public:
	table();
	table(const table &);

	table(const std::vector <var> &, const std::vector <ftr> &);
	table(const std::pair <std::vector <var>, std::vector <ftr>> &);

	template <class ... U>
	table(U ...);

	const table &operator=(const table &);

	~table();

	var &get_var(const std::string &);
	const var &find_var(const std::string &);
	
	ftr &get_ftr(const std::string &);
	const ftr &find_ftr(const std::string &);

	bool insert_var(const var &);
	bool insert_ftr(const ftr &);

	bool remove_var(const var &);
	bool remove_var(const std::string &);

	bool remove_ftr(const ftr &);
	bool remove_ftr(const std::string &);

	bool empty() const;
	bool empty_var() const;
	bool empty_ftr() const;

	std::size_t size() const;
	std::size_t size_var() const;
	std::size_t size_ftr() const;

	void clear();
	void clear_var_tree();
	void clear_ftr_tree();

	void print() const;
	void print_var() const;
	void print_ftr() const;
private:
	void gather(std::pair <std::vector <var>, std::vector <ftr>> &,
			var) const;
	
	template <class ... U>
	void gather(std::pair <std::vector <var>, std::vector <ftr>> &,
			var, U ...) const;
	
	void gather(std::pair <std::vector <var>, std::vector <ftr>> &,
			ftr) const;
	
	template <class ... U>
	void gather(std::pair <std::vector <var>, std::vector <ftr>> &,
			ftr, U ...) const;

	__var_node *clone_var(__var_node *);
	__ftr_node *clone_ftr(__ftr_node *);

	void clear_var_tree(__var_node *(&));
	void clear_ftr_tree(__ftr_node *(&));

	void print_var(__var_node *, int, int) const;
	void print_ftr(__ftr_node *, int, int) const;

	void splay_var(__var_node *(&), const std::string &);
	void splay_ftr(__ftr_node *(&), const std::string &);

	void rotate_var_left(__var_node *(&));
	void rotate_var_right(__var_node *(&));
	
	void rotate_ftr_left(__ftr_node *(&));
	void rotate_ftr_right(__ftr_node *(&));
public:
	// empty or null root nodes
	class null_tree {};

	// old nfe equivalent
	class null_entry {};
};

/* Constructors, destructors,
 * major/significant operators */
template <class T>
table <T> ::table() : vtree(nullptr), ftree(nullptr),
	vtree_size(0), ftree_size(0) {}

template <class T>
table <T> ::table(const table &other) : vtree(nullptr),
	ftree(nullptr), vtree_size(0), ftree_size(0)
{
	*this = other;
}

template <class T>
table <T> ::table(const std::vector <var> &vs, const std::vector <ftr> &fs)
	: table()
{
	for (auto vr : vs)
		insert_var(vr);
	for (auto ft : fs)
		insert_ftr(ft);
}

template <class T>
table <T> ::table(const std::pair <std::vector <var>, std::vector <ftr>> &pr)
	: table(pr.first, pr.second) {}

template <class T>
template <class ... U>
table <T> ::table(U ... args) : table()
{
	std::pair <std::vector <var>, std::vector <ftr>> pr;
	gather(pr, args...);

	for (auto vr : pr.first)
		insert_var(vr);
	for (auto ft : pr.second)
		insert_ftr(ft);
}

template <class T>
const table <T> &table <T> ::operator=(const table &other)
{
	if (this != &other) {
		clear();
		vtree = clone_var(other.vtree);
		ftree = clone_ftr(other.ftree);
		vtree_size = other.vtree_size;
		ftree_size = other.ftree_size;
	}

	// cout << string(50, '_') << endl;
	// cout << "ASSIGNMENT OPERATOR:" << endl;
	// print();

	return *this;
}

template <class T>
table <T> ::~table()
{
	clear();
}

/* Public interface of table;
 * find methods, clear, print, etc. */
template <class T>
typename table <T> ::var &table <T> ::get_var(const std::string &key)
{
	if (!vtree)
		throw null_tree();

	splay_var(vtree, key);

	if (vtree->val.symbol() != key)
		throw null_entry();

	return vtree->val;
}

template <class T>
const typename table <T> ::var &table <T> ::find_var(const std::string &key)
{
	if (!vtree)
		throw null_tree();

	splay_var(vtree, key);

	if (vtree->val.symbol() != key)
		throw null_entry();

	return vtree->val;
}

template <class T>
typename table <T> ::ftr &table <T> ::get_ftr(const std::string &key)
{
	if (!ftree)
		throw null_tree();

	splay_ftr(ftree, key);

	if (ftree->val.symbol() != key)
		throw null_entry();

	return ftree->val;
}

template <class T>
const typename table <T> ::ftr &table <T> ::find_ftr(const std::string &key)
{
	if (!ftree)
		throw null_tree();

	splay_ftr(ftree, key);

	if (ftree->val.symbol() != key)
		throw null_entry();

	return ftree->val;
}

template <class T>
bool table <T> ::insert_var(const var &x)
{
	if (vtree == nullptr) {
		vtree = new __var_node {x, nullptr, nullptr};
		vtree_size++;
		return true;
	}

	splay_var(vtree, x.symbol());

	__var_node *temp = new __var_node {x, nullptr, nullptr};

	if (x < vtree->val) {
		temp->left = vtree->left;
		temp->right = vtree;

		temp->right->left = nullptr;
		vtree = temp;
		vtree_size++;

		return true;
	}

	if (x > vtree->val) {
		temp->left = vtree;
		temp->right = vtree->right;

		temp->left->right = nullptr;
		vtree = temp;
		vtree_size++;

		return true;
	}

	return false;
}

template <class T>
bool table <T> ::remove_var(const var &x)
{
	if (!vtree_size)
		return false;

	splay_var(vtree, x.symbol());

	if (x != vtree->val)
		return false;

	__var_node *nnd;
	if (vtree->left == nullptr) {
		nnd = vtree->left;
	} else {
		nnd = vtree->left;
		splay_var(nnd, x.symbol());

		nnd->right = vtree->right;
	}

	delete vtree;

	vtree = nnd;
	vtree_size--;

	return true;
}

template <class T>
bool table <T> ::remove_var(const std::string &str)
{
	if (!vtree_size)
		return false;

	splay_var(vtree, str);

	if (str != vtree->val.symbol())
		return false;

	__var_node *nnd;
	if (vtree->left == nullptr) {
		nnd = vtree->left;
	} else {
		nnd = vtree->left;
		splay_var(nnd, str);

		nnd->right = vtree->right;
	}

	delete vtree;

	vtree = nnd;
	vtree_size--;

	return true;
}

template <class T>
bool table <T> ::insert_ftr(const ftr &x)
{
	if (ftree == nullptr) {
		ftree = new __ftr_node {x, nullptr, nullptr};
		ftree_size++;
		return true;
	}

	splay_ftr(ftree, x.symbol());

	__ftr_node *temp = new __ftr_node {x, nullptr, nullptr};

	if (x < ftree->val) {
		temp->left = ftree->left;
		temp->right = ftree;

		temp->right->left = nullptr;
		ftree = temp;
		ftree_size++;

		return true;
	}

	if (x > ftree->val) {
		temp->left = ftree;
		temp->right = ftree->right;

		temp->left->right = nullptr;
		ftree = temp;
		ftree_size++;

		return true;
	}

	return false;
}

template <class T>
bool table <T> ::remove_ftr(const ftr &x)
{
	if (!ftree_size)
		return false;

	splay_ftr(ftree, x.symbol());

	if (x.symbol() != ftree->val.symbol())
		return false;

	__ftr_node *nnd;
	if (ftree->left == nullptr) {
		nnd = ftree->left;
	} else {
		nnd = ftree->left;
		splay_ftr(nnd, x.symbol());

		nnd->right = ftree->right;
	}

	delete ftree;

	ftree = nnd;
	ftree_size--;

	return true;
}

template <class T>
bool table <T> ::remove_ftr(const std::string &str)
{
	if (!ftree_size)
		return false;

	splay_ftr(ftree, str);

	if (str != ftree->val.symbol())
		return false;

	__ftr_node *nnd;
	if (ftree->left == nullptr) {
		nnd = ftree->left;
	} else {
		nnd = ftree->left;
		splay_ftr(nnd, str);

		nnd->right = ftree->right;
	}

	delete ftree;

	ftree = nnd;
	ftree_size--;

	return true;
}

template <class T>
bool table <T> ::empty() const
{
	return !(vtree_size || ftree_size);
}

template <class T>
bool table <T> ::empty_var() const
{
	return !vtree_size;
}

template <class T>
bool table <T> ::empty_ftr() const
{
	return !ftree_size;
}

template <class T>
std::size_t table <T> ::size() const
{
	return vtree_size + ftree_size;
}

template <class T>
std::size_t table <T> ::size_var() const
{
	return vtree_size;
}

template <class T>
std::size_t table <T> ::size_ftr() const
{
	return ftree_size;
}

template <class T>
void table <T> ::clear()
{
	clear_var_tree();
	clear_ftr_tree();
}

template <class T>
void table <T> ::clear_var_tree()
{
	if (vtree != nullptr)
		clear_var_tree(vtree);
}

template <class T>
void table <T> ::clear_ftr_tree()
{
	if (ftree != nullptr)
		clear_ftr_tree(ftree);
}

template <class T>
void table <T> ::print() const
{
	cout << "VARIABLE TREE/STACK" << endl;
	print_var();

	cout << endl << "FUNCTOR TREE/STACK" << endl;
	print_ftr();
}

template <class T>
void table <T> ::print_var() const
{
	print_var(vtree, 1, 0);
}

template <class T>
void table <T> ::print_ftr() const
{
	print_ftr(ftree, 1, 0);
}

/* Protected methods (helpers methods);
 * splay, rotate left/right, clone, ect. */
template <class T>
void table <T> ::gather(std::pair <std::vector <var>, std::vector <ftr>> &pr,
		var vs) const
{
	pr.first.push_back(vs);
}

template <class T>
template <class ... U>
void table <T> ::gather(std::pair <std::vector <var>, std::vector <ftr>> &pr,
		var vs, U ... args) const
{
	pr.first.push_back(vs);
	gather(pr, args...);
}

template <class T>
void table <T> ::gather(std::pair <std::vector <var>, std::vector <ftr>> &pr,
		ftr ft) const
{
	pr.second.push_back(ft);
}

template <class T>
template <class ... U>
void table <T> ::gather(std::pair <std::vector <var>, std::vector <ftr>> &pr,
		ftr ft, U ... args) const
{
	pr.second.push_back(ft);
	gather(pr, args...);
}

template <class T>
typename table <T> ::__var_node *table <T> ::clone_var(__var_node *vnd)
{
	__var_node *nnode;

	if (vnd == nullptr)
		return nullptr;

	nnode = new __var_node {vnd->val, clone_var(vnd->left),
		clone_var(vnd->right)};

	return nnode;
}

template <class T>
typename table <T> ::__ftr_node *table <T> ::clone_ftr(__ftr_node *fnd)
{
	__ftr_node *nnode;

	if (fnd == nullptr)
		return nullptr;

	nnode = new __ftr_node {fnd->val, clone_ftr(fnd->left),
		clone_ftr(fnd->right)};

	return nnode;
}

template <class T>
void table <T> ::clear_var_tree(__var_node *(&vnd))
{
	if (vnd == nullptr)
		return;

	clear_var_tree(vnd->left);
	clear_var_tree(vnd->right);

	delete vnd;
	
	// maybe remove later
	vnd = nullptr;
	vtree_size--;
}

template <class T>
void table <T> ::clear_ftr_tree(__ftr_node *(&fnd))
{
	if (fnd == nullptr)
		return;

	clear_ftr_tree(fnd->left);
	clear_ftr_tree(fnd->right);

	delete fnd;
	
	// maybe remove later
	fnd = nullptr;
	ftree_size--;
}

template <class T>
void table <T> ::print_var(__var_node *vnd, int lev, int dir) const
{
	if (vnd == nullptr)
		return;

	for (int i = 0; i < lev; i++)
		std::cout << "\t";

	switch (dir) {
	case 0:
		std::cout << "Level #" << lev << " -- Root: ";

		if (vnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << vnd->val;
		std::cout << " [@" << vnd << "]" << std::endl;
		break;
	case 1:
		std::cout << "Level #" << lev << " -- Left: ";
		
		if (vnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << vnd->val;
		std::cout << " [@" << vnd << "]" << std::endl;
		break;
	case -1:
		std::cout << "Level #" << lev << " -- Right: ";
		
		if (vnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << vnd->val;
		std::cout << " [@" << vnd << "]" << std::endl;
		break;
	}
	
	if (vnd == nullptr)
		return;

	print_var(vnd->left, lev + 1, 1);
	print_var(vnd->right, lev + 1, -1);
}

template <class T>
void table <T> ::print_ftr(__ftr_node *fnd, int lev, int dir) const
{
	if (fnd == nullptr)
		return;

	for (int i = 0; i < lev; i++)
		std::cout << "\t";

	switch (dir) {
	case 0:
		std::cout << "Level #" << lev << " -- Root: ";

		if (fnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << fnd->val;
		std::cout << " [@" << fnd << "]" << std::endl;
		break;
	case 1:
		std::cout << "Level #" << lev << " -- Left: ";
		
		if (fnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << fnd->val;
		std::cout << " [@" << fnd << "]" << std::endl;
		break;
	case -1:
		std::cout << "Level #" << lev << " -- Right: ";
		
		if (fnd == nullptr)
			std::cout << "NULL";
		else
			std::cout << fnd->val;
		std::cout << " [@" << fnd << "]" << std::endl;
		break;
	}
	
	if (fnd == nullptr)
		return;

	print_ftr(fnd->left, lev + 1, 1);
	print_ftr(fnd->right, lev + 1, -1);
}

template <class T>
void table <T> ::splay_var(__var_node *(&vnd), const std::string &id)
{
	__var_node *rt = nullptr;
	__var_node *lt = nullptr;
	__var_node *rtm = nullptr;
	__var_node *ltm = nullptr;
	
	while (vnd != nullptr) {
		if (id < vnd->val.symbol()) {
			if (vnd->left == nullptr)
				break;
			
			if (id < vnd->left->val.symbol()) {
				rotate_var_left(vnd);

				if (vnd->left == nullptr)
					break;
			}

			if (rt == nullptr)
				rt = new __var_node {var(), nullptr, nullptr};
		

			if (rtm == nullptr) {
				rt->left = vnd;
				rtm = rt;
			} else {
				rtm->left = vnd;
			}

			rtm = rtm->left;
			
			vnd = rtm->left;
			rtm->left = nullptr;
		} else if (id > vnd->val.symbol()) {
			if (vnd->right == nullptr)
				break;
			
			if (id > vnd->right->val.symbol()) {
				rotate_var_right(vnd);
				if (vnd->right == nullptr)
					break;
			}

			if (lt == nullptr)
				lt = new __var_node {var(), nullptr, nullptr};

			if (ltm == nullptr) {
				lt->right = vnd;
				ltm = lt;
			} else {
				ltm->right = vnd;
			}

			ltm = ltm->right;

			vnd = ltm->right;
			ltm->right = nullptr;
		} else {
			break;
		}
	}
	
	if (lt != nullptr) {
		ltm->right = vnd->left;
		vnd->left = lt->right;
	}

	if (rt != nullptr) {
		rtm->left = vnd->right;
		vnd->right = rt->left;
	}
}

template <class T>
void table <T> ::splay_ftr(__ftr_node *(&fnd), const std::string &id)
{
	__ftr_node *rt = nullptr;
	__ftr_node *lt = nullptr;
	__ftr_node *rtm = nullptr;
	__ftr_node *ltm = nullptr;
	
	while (fnd != nullptr) {
		if (id < fnd->val.symbol()) {
			if (fnd->left == nullptr)
				break;
			
			if (id < fnd->left->val.symbol()) {
				rotate_ftr_left(fnd);

				if (fnd->left == nullptr)
					break;
			}

			if (rt == nullptr)
				rt = new __ftr_node {ftr(), nullptr, nullptr};
		

			if (rtm == nullptr) {
				rt->left = fnd;
				rtm = rt;
			} else {
				rtm->left = fnd;
			}

			rtm = rtm->left;
			
			fnd = rtm->left;
			rtm->left = nullptr;
		} else if (id > fnd->val.symbol()) {
			if (fnd->right == nullptr)
				break;
			
			if (id > fnd->right->val.symbol()) {
				rotate_ftr_right(fnd);
				if (fnd->right == nullptr)
					break;
			}

			if (lt == nullptr)
				lt = new __ftr_node {ftr(), nullptr, nullptr};

			if (ltm == nullptr) {
				lt->right = fnd;
				ltm = lt;
			} else {
				ltm->right = fnd;
			}

			ltm = ltm->right;

			fnd = ltm->right;
			ltm->right = nullptr;
		} else {
			break;
		}
	}
	
	if (lt != nullptr) {
		ltm->right = fnd->left;
		fnd->left = lt->right;
	}

	if (rt != nullptr) {
		rtm->left = fnd->right;
		fnd->right = rt->left;
	}
}

template <class T>
void table <T> ::rotate_var_left(__var_node *(&vnd))
{
	__var_node *rt = vnd->left;

	vnd->left = rt->right;
	rt->right = vnd;
	vnd = rt;
}

template <class T>
void table <T> ::rotate_var_right(__var_node *(&vnd))
{
	__var_node *rt = vnd->right;

	vnd->right = rt->left;
	rt->left = vnd;
	vnd = rt;
}

template <class T>
void table <T> ::rotate_ftr_left(__ftr_node *(&fnd))
{
	__ftr_node *rt = fnd->left;

	fnd->left = rt->right;
	rt->right = fnd;
	fnd = rt;
}

template <class T>
void table <T> ::rotate_ftr_right(__ftr_node *(&fnd))
{
	__ftr_node *rt = fnd->right;

	fnd->right = rt->left;
	rt->left = fnd;
	fnd = rt;
}

#endif
