---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: Splay Tree(set)

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cbed23bc82f8d451042dd45b42d995ac">lib/data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data-structure/splay-tree-set.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 04:11:49+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
const int MAX_SIZE = 200020;

using T = int;

class Set{
public:
	struct Node{
		Node* l,* r,* p; 
		int size;
		T val;
		Node():l(nullptr),r(nullptr),p(nullptr),size(1),val(T()){}
		void rotate(){
			Node* c; 
			if(p->l==this){
				c = r;
				r = p;
				p->l = c;
			}
			else{
				c = l;
				l = p;
				p->r = c;
			}
			if(p->p && p->p->l == p)p->p->l = this;
			if(p->p && p->p->r == p)p->p->r = this;

			Node* prv_p = p;
			p = p->p;
			prv_p->p = this;
			if(c)c->p = prv_p;

			prv_p->update();
			update();
		}
		int pdirection(){
			if(!p)return 0;
			return p->l == this ? 1 : -1;
		}
		Node* splay(){
			while(pdirection()){
				if(!p->pdirection()){
					rotate();
				}
				else if(p->pdirection() == pdirection()){
					p->rotate();
					rotate();
				}
				else{
					rotate();
					rotate();
				}
			}
			return this;
		}

		void update(){
			size = 1;
			if(l)size += l->size;
			if(r)size += r->size;
		}
	};

private:
	static Node node[MAX_SIZE];
	static int _size;
	Node* _root;

public:
	Set(): _root(nullptr){};

	Node* root(){return _root;}
	int size(){
		if(!root()) return 0;
		return root()->size;
	}

	Node* nth(int n){
		if(n >= size())return nullptr;
		Node* cur = root();
		while(cur){
			int lsize = cur->l ? cur->l->size : 0;
			if(n < lsize){
				cur = cur->l;
			}
			else if(n == lsize){
				return _root = cur->splay();
			}
			else{
				cur = cur->r;
				n -= lsize + 1;
			}
		}

		return nullptr;
	}
	bool find(T x){
		Node* cur = root(), * prv = nullptr;
		while(cur){
			prv = cur;
			if(x < cur->val){
				cur = cur->l;
			}
			else if(x == cur->val){
				_root = cur->splay();
				return 1;
			}
			else{
				cur = cur->r;
			}
		}
		prv ? _root = prv->splay() : nullptr;
		return 0;
	}
	void merge(Node* r_root){ 
		if(!r_root)return;
		nth(size() - 1);
		root()->r = r_root;
		r_root->p = root();
		root()->update();
	}
	void merge(Set& s){
		merge(s.root());
	}
	void insert(T x){
		if(!find(x)){
			node[_size].val = x;
			if(!root()){
				_root = node + _size++;
				return;
			}
			if(x < root()->val){
				node[_size].r = root();
				root()->p = node + _size;
				if(root()->l){
					node[_size].l = root()->l;
					root()->l->p = node + _size;
					root()->l = nullptr;
				}
			}
			else{
				node[_size].l = root();
				root()->p = node + _size;
				if(root()->r){
					node[_size].r = root()->r;
					root()->r->p = node + _size;
					root()->r = nullptr;
				}
			}
			root()->update();
			node[_size].update();
			_root = node + _size++;
		}
	}
	void erase(T x){
		if(find(x)){
			Node* prv_root = root(),* prv_l = root()->l,* prv_r = root()->r;
			if(!prv_root->l){
				_root = prv_root->r;
			}
			else{
				prv_l->p = nullptr;
				prv_root->l = nullptr;
			}
			if(!prv_root->r){
				_root = prv_l;
			}
			else{
				prv_r->p = nullptr;
				prv_root->r = nullptr;
			}
			if(prv_l && prv_r){
				_root = prv_l;
				merge(prv_r);
			}
		}
	}

	template<class F>
	void tour(Node* v, F f, int d = 0, int dir = 0){
		if(v){
			tour(v->l, f, d+1, -1);
			f(v, d, dir);
			tour(v->r, f, d+1, 1);
		}
	}
	void print_tree(){
		tour(root(),[&](Node* v, int d, int dir){
			std::cout << std::string(2*d,' ');
			if(dir == -1)std::cout << "/  ";
			if(dir == 0)std::cout << "-  ";
			if(dir == 1)std::cout << "\\  ";
			std::cout << v->val << '\n';
		});
	}
	void print(){
		std::cout << "{ ";
		tour(root(),[&](Node* v, int, int){
			std::cout << v->val << ", ";
		});
		std::cout << "}";
	}
};
std::ostream& operator<<(std::ostream&os, Set&rhs){rhs.print();return os; }
Set operator+=(Set& l, Set& r){
	r.tour(r.root(),[&](Set::Node* v,int,int){
		l.insert(v->val);
	});
	return l;
}
Set operator+(Set& l, Set& r){
	Set ret;
	l.tour(l.root(),[&](Set::Node* v,int,int){
		ret.insert(v->val);
	});
	r.tour(r.root(),[&](Set::Node* v,int,int){
		ret.insert(v->val);
	});
	return ret;
}
Set operator*=(Set& l, Set& r){
	r.tour(r.root(),[&](Set::Node* v,int,int){
		if(!l.find(v->val))l.erase(v->val);
	});
	return l;
}
Set operator*(Set& l, Set& r){
	Set ret;
	l.tour(l.root(),[&](Set::Node* v,int,int){
		if(r.find(v->val))ret.insert(v->val);
	});
	return ret;
}

Set::Node Set::node[MAX_SIZE];
int Set::_size = 0;


/**
* @title Splay Tree(set)
*/

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "lib/data-structure/splay-tree-set.hpp"
const int MAX_SIZE = 200020;

using T = int;

class Set{
public:
	struct Node{
		Node* l,* r,* p; 
		int size;
		T val;
		Node():l(nullptr),r(nullptr),p(nullptr),size(1),val(T()){}
		void rotate(){
			Node* c; 
			if(p->l==this){
				c = r;
				r = p;
				p->l = c;
			}
			else{
				c = l;
				l = p;
				p->r = c;
			}
			if(p->p && p->p->l == p)p->p->l = this;
			if(p->p && p->p->r == p)p->p->r = this;

			Node* prv_p = p;
			p = p->p;
			prv_p->p = this;
			if(c)c->p = prv_p;

			prv_p->update();
			update();
		}
		int pdirection(){
			if(!p)return 0;
			return p->l == this ? 1 : -1;
		}
		Node* splay(){
			while(pdirection()){
				if(!p->pdirection()){
					rotate();
				}
				else if(p->pdirection() == pdirection()){
					p->rotate();
					rotate();
				}
				else{
					rotate();
					rotate();
				}
			}
			return this;
		}

		void update(){
			size = 1;
			if(l)size += l->size;
			if(r)size += r->size;
		}
	};

private:
	static Node node[MAX_SIZE];
	static int _size;
	Node* _root;

public:
	Set(): _root(nullptr){};

	Node* root(){return _root;}
	int size(){
		if(!root()) return 0;
		return root()->size;
	}

	Node* nth(int n){
		if(n >= size())return nullptr;
		Node* cur = root();
		while(cur){
			int lsize = cur->l ? cur->l->size : 0;
			if(n < lsize){
				cur = cur->l;
			}
			else if(n == lsize){
				return _root = cur->splay();
			}
			else{
				cur = cur->r;
				n -= lsize + 1;
			}
		}

		return nullptr;
	}
	bool find(T x){
		Node* cur = root(), * prv = nullptr;
		while(cur){
			prv = cur;
			if(x < cur->val){
				cur = cur->l;
			}
			else if(x == cur->val){
				_root = cur->splay();
				return 1;
			}
			else{
				cur = cur->r;
			}
		}
		prv ? _root = prv->splay() : nullptr;
		return 0;
	}
	void merge(Node* r_root){ 
		if(!r_root)return;
		nth(size() - 1);
		root()->r = r_root;
		r_root->p = root();
		root()->update();
	}
	void merge(Set& s){
		merge(s.root());
	}
	void insert(T x){
		if(!find(x)){
			node[_size].val = x;
			if(!root()){
				_root = node + _size++;
				return;
			}
			if(x < root()->val){
				node[_size].r = root();
				root()->p = node + _size;
				if(root()->l){
					node[_size].l = root()->l;
					root()->l->p = node + _size;
					root()->l = nullptr;
				}
			}
			else{
				node[_size].l = root();
				root()->p = node + _size;
				if(root()->r){
					node[_size].r = root()->r;
					root()->r->p = node + _size;
					root()->r = nullptr;
				}
			}
			root()->update();
			node[_size].update();
			_root = node + _size++;
		}
	}
	void erase(T x){
		if(find(x)){
			Node* prv_root = root(),* prv_l = root()->l,* prv_r = root()->r;
			if(!prv_root->l){
				_root = prv_root->r;
			}
			else{
				prv_l->p = nullptr;
				prv_root->l = nullptr;
			}
			if(!prv_root->r){
				_root = prv_l;
			}
			else{
				prv_r->p = nullptr;
				prv_root->r = nullptr;
			}
			if(prv_l && prv_r){
				_root = prv_l;
				merge(prv_r);
			}
		}
	}

	template<class F>
	void tour(Node* v, F f, int d = 0, int dir = 0){
		if(v){
			tour(v->l, f, d+1, -1);
			f(v, d, dir);
			tour(v->r, f, d+1, 1);
		}
	}
	void print_tree(){
		tour(root(),[&](Node* v, int d, int dir){
			std::cout << std::string(2*d,' ');
			if(dir == -1)std::cout << "/  ";
			if(dir == 0)std::cout << "-  ";
			if(dir == 1)std::cout << "\\  ";
			std::cout << v->val << '\n';
		});
	}
	void print(){
		std::cout << "{ ";
		tour(root(),[&](Node* v, int, int){
			std::cout << v->val << ", ";
		});
		std::cout << "}";
	}
};
std::ostream& operator<<(std::ostream&os, Set&rhs){rhs.print();return os; }
Set operator+=(Set& l, Set& r){
	r.tour(r.root(),[&](Set::Node* v,int,int){
		l.insert(v->val);
	});
	return l;
}
Set operator+(Set& l, Set& r){
	Set ret;
	l.tour(l.root(),[&](Set::Node* v,int,int){
		ret.insert(v->val);
	});
	r.tour(r.root(),[&](Set::Node* v,int,int){
		ret.insert(v->val);
	});
	return ret;
}
Set operator*=(Set& l, Set& r){
	r.tour(r.root(),[&](Set::Node* v,int,int){
		if(!l.find(v->val))l.erase(v->val);
	});
	return l;
}
Set operator*(Set& l, Set& r){
	Set ret;
	l.tour(l.root(),[&](Set::Node* v,int,int){
		if(r.find(v->val))ret.insert(v->val);
	});
	return ret;
}

Set::Node Set::node[MAX_SIZE];
int Set::_size = 0;


/**
* @title Splay Tree(set)
*/

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

