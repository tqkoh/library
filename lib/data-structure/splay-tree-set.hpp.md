---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Splay Tree(set)
    links: []
  bundledCode: "#line 2 \"lib/data-structure/splay-tree-set.hpp\"\nconst int MAX_SIZE\
    \ = 200020;\n\nusing T = int;\n\nclass Set{\npublic:\n\tstruct Node{\n\t\tNode*\
    \ l,* r,* p; \n\t\tint size;\n\t\tT val;\n\t\tNode():l(nullptr),r(nullptr),p(nullptr),size(1),val(T()){}\n\
    \t\tvoid rotate(){\n\t\t\tNode* c; \n\t\t\tif(p->l==this){\n\t\t\t\tc = r;\n\t\
    \t\t\tr = p;\n\t\t\t\tp->l = c;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tc = l;\n\t\t\t\t\
    l = p;\n\t\t\t\tp->r = c;\n\t\t\t}\n\t\t\tif(p->p && p->p->l == p)p->p->l = this;\n\
    \t\t\tif(p->p && p->p->r == p)p->p->r = this;\n\n\t\t\tNode* prv_p = p;\n\t\t\t\
    p = p->p;\n\t\t\tprv_p->p = this;\n\t\t\tif(c)c->p = prv_p;\n\n\t\t\tprv_p->update();\n\
    \t\t\tupdate();\n\t\t}\n\t\tint pdirection(){\n\t\t\tif(!p)return 0;\n\t\t\treturn\
    \ p->l == this ? 1 : -1;\n\t\t}\n\t\tNode* splay(){\n\t\t\twhile(pdirection()){\n\
    \t\t\t\tif(!p->pdirection()){\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\t\t\telse if(p->pdirection()\
    \ == pdirection()){\n\t\t\t\t\tp->rotate();\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\
    \t\t\telse{\n\t\t\t\t\trotate();\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn this;\n\t\t}\n\n\t\tvoid update(){\n\t\t\tsize = 1;\n\t\t\tif(l)size\
    \ += l->size;\n\t\t\tif(r)size += r->size;\n\t\t}\n\t};\n\nprivate:\n\tstatic\
    \ Node node[MAX_SIZE];\n\tstatic int _size;\n\tNode* _root;\n\npublic:\n\tSet():\
    \ _root(nullptr){};\n\n\tNode* root(){return _root;}\n\tint size(){\n\t\tif(!root())\
    \ return 0;\n\t\treturn root()->size;\n\t}\n\n\tNode* nth(int n){\n\t\tif(n >=\
    \ size())return nullptr;\n\t\tNode* cur = root();\n\t\twhile(cur){\n\t\t\tint\
    \ lsize = cur->l ? cur->l->size : 0;\n\t\t\tif(n < lsize){\n\t\t\t\tcur = cur->l;\n\
    \t\t\t}\n\t\t\telse if(n == lsize){\n\t\t\t\treturn _root = cur->splay();\n\t\t\
    \t}\n\t\t\telse{\n\t\t\t\tcur = cur->r;\n\t\t\t\tn -= lsize + 1;\n\t\t\t}\n\t\t\
    }\n\n\t\treturn nullptr;\n\t}\n\tbool find(T x){\n\t\tNode* cur = root(), * prv\
    \ = nullptr;\n\t\twhile(cur){\n\t\t\tprv = cur;\n\t\t\tif(x < cur->val){\n\t\t\
    \t\tcur = cur->l;\n\t\t\t}\n\t\t\telse if(x == cur->val){\n\t\t\t\t_root = cur->splay();\n\
    \t\t\t\treturn 1;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tcur = cur->r;\n\t\t\t}\n\t\t\
    }\n\t\tprv ? _root = prv->splay() : nullptr;\n\t\treturn 0;\n\t}\n\tvoid merge(Node*\
    \ r_root){ \n\t\tif(!r_root)return;\n\t\tnth(size() - 1);\n\t\troot()->r = r_root;\n\
    \t\tr_root->p = root();\n\t\troot()->update();\n\t}\n\tvoid merge(Set& s){\n\t\
    \tmerge(s.root());\n\t}\n\tvoid insert(T x){\n\t\tif(!find(x)){\n\t\t\tnode[_size].val\
    \ = x;\n\t\t\tif(!root()){\n\t\t\t\t_root = node + _size++;\n\t\t\t\treturn;\n\
    \t\t\t}\n\t\t\tif(x < root()->val){\n\t\t\t\tnode[_size].r = root();\n\t\t\t\t\
    root()->p = node + _size;\n\t\t\t\tif(root()->l){\n\t\t\t\t\tnode[_size].l = root()->l;\n\
    \t\t\t\t\troot()->l->p = node + _size;\n\t\t\t\t\troot()->l = nullptr;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\telse{\n\t\t\t\tnode[_size].l = root();\n\t\t\t\troot()->p\
    \ = node + _size;\n\t\t\t\tif(root()->r){\n\t\t\t\t\tnode[_size].r = root()->r;\n\
    \t\t\t\t\troot()->r->p = node + _size;\n\t\t\t\t\troot()->r = nullptr;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\troot()->update();\n\t\t\tnode[_size].update();\n\t\t\t_root\
    \ = node + _size++;\n\t\t}\n\t}\n\tvoid erase(T x){\n\t\tif(find(x)){\n\t\t\t\
    Node* prv_root = root(),* prv_l = root()->l,* prv_r = root()->r;\n\t\t\tif(!prv_root->l){\n\
    \t\t\t\t_root = prv_root->r;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tprv_l->p = nullptr;\n\
    \t\t\t\tprv_root->l = nullptr;\n\t\t\t}\n\t\t\tif(!prv_root->r){\n\t\t\t\t_root\
    \ = prv_l;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tprv_r->p = nullptr;\n\t\t\t\tprv_root->r\
    \ = nullptr;\n\t\t\t}\n\t\t\tif(prv_l && prv_r){\n\t\t\t\t_root = prv_l;\n\t\t\
    \t\tmerge(prv_r);\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<class F>\n\tvoid tour(Node*\
    \ v, F f, int d = 0, int dir = 0){\n\t\tif(v){\n\t\t\ttour(v->l, f, d+1, -1);\n\
    \t\t\tf(v, d, dir);\n\t\t\ttour(v->r, f, d+1, 1);\n\t\t}\n\t}\n\tvoid print_tree(){\n\
    \t\ttour(root(),[&](Node* v, int d, int dir){\n\t\t\tstd::cout << std::string(2*d,'\
    \ ');\n\t\t\tif(dir == -1)std::cout << \"/  \";\n\t\t\tif(dir == 0)std::cout <<\
    \ \"-  \";\n\t\t\tif(dir == 1)std::cout << \"\\\\  \";\n\t\t\tstd::cout << v->val\
    \ << '\\n';\n\t\t});\n\t}\n\tvoid print(){\n\t\tstd::cout << \"{ \";\n\t\ttour(root(),[&](Node*\
    \ v, int, int){\n\t\t\tstd::cout << v->val << \", \";\n\t\t});\n\t\tstd::cout\
    \ << \"}\";\n\t}\n};\nstd::ostream& operator<<(std::ostream&os, Set&rhs){rhs.print();return\
    \ os; }\nSet operator+=(Set& l, Set& r){\n\tr.tour(r.root(),[&](Set::Node* v,int,int){\n\
    \t\tl.insert(v->val);\n\t});\n\treturn l;\n}\nSet operator+(Set& l, Set& r){\n\
    \tSet ret;\n\tl.tour(l.root(),[&](Set::Node* v,int,int){\n\t\tret.insert(v->val);\n\
    \t});\n\tr.tour(r.root(),[&](Set::Node* v,int,int){\n\t\tret.insert(v->val);\n\
    \t});\n\treturn ret;\n}\nSet operator*=(Set& l, Set& r){\n\tr.tour(r.root(),[&](Set::Node*\
    \ v,int,int){\n\t\tif(!l.find(v->val))l.erase(v->val);\n\t});\n\treturn l;\n}\n\
    Set operator*(Set& l, Set& r){\n\tSet ret;\n\tl.tour(l.root(),[&](Set::Node* v,int,int){\n\
    \t\tif(r.find(v->val))ret.insert(v->val);\n\t});\n\treturn ret;\n}\n\nSet::Node\
    \ Set::node[MAX_SIZE];\nint Set::_size = 0;\n\n\n/**\n* @title Splay Tree(set)\n\
    */\n"
  code: "#pragma once\nconst int MAX_SIZE = 200020;\n\nusing T = int;\n\nclass Set{\n\
    public:\n\tstruct Node{\n\t\tNode* l,* r,* p; \n\t\tint size;\n\t\tT val;\n\t\t\
    Node():l(nullptr),r(nullptr),p(nullptr),size(1),val(T()){}\n\t\tvoid rotate(){\n\
    \t\t\tNode* c; \n\t\t\tif(p->l==this){\n\t\t\t\tc = r;\n\t\t\t\tr = p;\n\t\t\t\
    \tp->l = c;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tc = l;\n\t\t\t\tl = p;\n\t\t\t\tp->r\
    \ = c;\n\t\t\t}\n\t\t\tif(p->p && p->p->l == p)p->p->l = this;\n\t\t\tif(p->p\
    \ && p->p->r == p)p->p->r = this;\n\n\t\t\tNode* prv_p = p;\n\t\t\tp = p->p;\n\
    \t\t\tprv_p->p = this;\n\t\t\tif(c)c->p = prv_p;\n\n\t\t\tprv_p->update();\n\t\
    \t\tupdate();\n\t\t}\n\t\tint pdirection(){\n\t\t\tif(!p)return 0;\n\t\t\treturn\
    \ p->l == this ? 1 : -1;\n\t\t}\n\t\tNode* splay(){\n\t\t\twhile(pdirection()){\n\
    \t\t\t\tif(!p->pdirection()){\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\t\t\telse if(p->pdirection()\
    \ == pdirection()){\n\t\t\t\t\tp->rotate();\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\
    \t\t\telse{\n\t\t\t\t\trotate();\n\t\t\t\t\trotate();\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn this;\n\t\t}\n\n\t\tvoid update(){\n\t\t\tsize = 1;\n\t\t\tif(l)size\
    \ += l->size;\n\t\t\tif(r)size += r->size;\n\t\t}\n\t};\n\nprivate:\n\tstatic\
    \ Node node[MAX_SIZE];\n\tstatic int _size;\n\tNode* _root;\n\npublic:\n\tSet():\
    \ _root(nullptr){};\n\n\tNode* root(){return _root;}\n\tint size(){\n\t\tif(!root())\
    \ return 0;\n\t\treturn root()->size;\n\t}\n\n\tNode* nth(int n){\n\t\tif(n >=\
    \ size())return nullptr;\n\t\tNode* cur = root();\n\t\twhile(cur){\n\t\t\tint\
    \ lsize = cur->l ? cur->l->size : 0;\n\t\t\tif(n < lsize){\n\t\t\t\tcur = cur->l;\n\
    \t\t\t}\n\t\t\telse if(n == lsize){\n\t\t\t\treturn _root = cur->splay();\n\t\t\
    \t}\n\t\t\telse{\n\t\t\t\tcur = cur->r;\n\t\t\t\tn -= lsize + 1;\n\t\t\t}\n\t\t\
    }\n\n\t\treturn nullptr;\n\t}\n\tbool find(T x){\n\t\tNode* cur = root(), * prv\
    \ = nullptr;\n\t\twhile(cur){\n\t\t\tprv = cur;\n\t\t\tif(x < cur->val){\n\t\t\
    \t\tcur = cur->l;\n\t\t\t}\n\t\t\telse if(x == cur->val){\n\t\t\t\t_root = cur->splay();\n\
    \t\t\t\treturn 1;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tcur = cur->r;\n\t\t\t}\n\t\t\
    }\n\t\tprv ? _root = prv->splay() : nullptr;\n\t\treturn 0;\n\t}\n\tvoid merge(Node*\
    \ r_root){ \n\t\tif(!r_root)return;\n\t\tnth(size() - 1);\n\t\troot()->r = r_root;\n\
    \t\tr_root->p = root();\n\t\troot()->update();\n\t}\n\tvoid merge(Set& s){\n\t\
    \tmerge(s.root());\n\t}\n\tvoid insert(T x){\n\t\tif(!find(x)){\n\t\t\tnode[_size].val\
    \ = x;\n\t\t\tif(!root()){\n\t\t\t\t_root = node + _size++;\n\t\t\t\treturn;\n\
    \t\t\t}\n\t\t\tif(x < root()->val){\n\t\t\t\tnode[_size].r = root();\n\t\t\t\t\
    root()->p = node + _size;\n\t\t\t\tif(root()->l){\n\t\t\t\t\tnode[_size].l = root()->l;\n\
    \t\t\t\t\troot()->l->p = node + _size;\n\t\t\t\t\troot()->l = nullptr;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\telse{\n\t\t\t\tnode[_size].l = root();\n\t\t\t\troot()->p\
    \ = node + _size;\n\t\t\t\tif(root()->r){\n\t\t\t\t\tnode[_size].r = root()->r;\n\
    \t\t\t\t\troot()->r->p = node + _size;\n\t\t\t\t\troot()->r = nullptr;\n\t\t\t\
    \t}\n\t\t\t}\n\t\t\troot()->update();\n\t\t\tnode[_size].update();\n\t\t\t_root\
    \ = node + _size++;\n\t\t}\n\t}\n\tvoid erase(T x){\n\t\tif(find(x)){\n\t\t\t\
    Node* prv_root = root(),* prv_l = root()->l,* prv_r = root()->r;\n\t\t\tif(!prv_root->l){\n\
    \t\t\t\t_root = prv_root->r;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tprv_l->p = nullptr;\n\
    \t\t\t\tprv_root->l = nullptr;\n\t\t\t}\n\t\t\tif(!prv_root->r){\n\t\t\t\t_root\
    \ = prv_l;\n\t\t\t}\n\t\t\telse{\n\t\t\t\tprv_r->p = nullptr;\n\t\t\t\tprv_root->r\
    \ = nullptr;\n\t\t\t}\n\t\t\tif(prv_l && prv_r){\n\t\t\t\t_root = prv_l;\n\t\t\
    \t\tmerge(prv_r);\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<class F>\n\tvoid tour(Node*\
    \ v, F f, int d = 0, int dir = 0){\n\t\tif(v){\n\t\t\ttour(v->l, f, d+1, -1);\n\
    \t\t\tf(v, d, dir);\n\t\t\ttour(v->r, f, d+1, 1);\n\t\t}\n\t}\n\tvoid print_tree(){\n\
    \t\ttour(root(),[&](Node* v, int d, int dir){\n\t\t\tstd::cout << std::string(2*d,'\
    \ ');\n\t\t\tif(dir == -1)std::cout << \"/  \";\n\t\t\tif(dir == 0)std::cout <<\
    \ \"-  \";\n\t\t\tif(dir == 1)std::cout << \"\\\\  \";\n\t\t\tstd::cout << v->val\
    \ << '\\n';\n\t\t});\n\t}\n\tvoid print(){\n\t\tstd::cout << \"{ \";\n\t\ttour(root(),[&](Node*\
    \ v, int, int){\n\t\t\tstd::cout << v->val << \", \";\n\t\t});\n\t\tstd::cout\
    \ << \"}\";\n\t}\n};\nstd::ostream& operator<<(std::ostream&os, Set&rhs){rhs.print();return\
    \ os; }\nSet operator+=(Set& l, Set& r){\n\tr.tour(r.root(),[&](Set::Node* v,int,int){\n\
    \t\tl.insert(v->val);\n\t});\n\treturn l;\n}\nSet operator+(Set& l, Set& r){\n\
    \tSet ret;\n\tl.tour(l.root(),[&](Set::Node* v,int,int){\n\t\tret.insert(v->val);\n\
    \t});\n\tr.tour(r.root(),[&](Set::Node* v,int,int){\n\t\tret.insert(v->val);\n\
    \t});\n\treturn ret;\n}\nSet operator*=(Set& l, Set& r){\n\tr.tour(r.root(),[&](Set::Node*\
    \ v,int,int){\n\t\tif(!l.find(v->val))l.erase(v->val);\n\t});\n\treturn l;\n}\n\
    Set operator*(Set& l, Set& r){\n\tSet ret;\n\tl.tour(l.root(),[&](Set::Node* v,int,int){\n\
    \t\tif(r.find(v->val))ret.insert(v->val);\n\t});\n\treturn ret;\n}\n\nSet::Node\
    \ Set::node[MAX_SIZE];\nint Set::_size = 0;\n\n\n/**\n* @title Splay Tree(set)\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/splay-tree-set.hpp
  requiredBy: []
  timestamp: '2020-08-07 04:11:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/data-structure/splay-tree-set.hpp
layout: document
redirect_from:
- /library/lib/data-structure/splay-tree-set.hpp
- /library/lib/data-structure/splay-tree-set.hpp.html
title: Splay Tree(set)
---
