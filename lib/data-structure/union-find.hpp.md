---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/union-find.test.cpp
    title: test/data-structure/union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"lib/data-structure/union-find.hpp\"\nclass UnionFind{\n\
    public:\n\tvector<int>par,rank;\n\tUnionFind(int n){\n\t\tpar.resize(n);rank.resize(n,0);\n\
    \t\tfor(int i=0;i<n;++i)par[i]=i;\n\t}\n\tint root(int x){\n\t\treturn x==par[x]?x:par[x]=root(par[x]);\n\
    \t}\n\tbool same(int x,int y){\n\t\treturn root(x)==root(y);\n\t}\n\tvoid unite(int\
    \ x,int y){\n\t\tx=root(x);\n\t\ty=root(y);\n\t\tif(x==y)return;\n\t\tif(rank[x]<rank[y])par[x]=y;\n\
    \t\telse{\n\t\t\tpar[y]=x;\n\t\t\tif(rank[x]==rank[y])++rank[x];\n\t\t}\n\t}\n\
    };\n\n/**\n* @title Union Find\n*/\n"
  code: "#pragma once\nclass UnionFind{\npublic:\n\tvector<int>par,rank;\n\tUnionFind(int\
    \ n){\n\t\tpar.resize(n);rank.resize(n,0);\n\t\tfor(int i=0;i<n;++i)par[i]=i;\n\
    \t}\n\tint root(int x){\n\t\treturn x==par[x]?x:par[x]=root(par[x]);\n\t}\n\t\
    bool same(int x,int y){\n\t\treturn root(x)==root(y);\n\t}\n\tvoid unite(int x,int\
    \ y){\n\t\tx=root(x);\n\t\ty=root(y);\n\t\tif(x==y)return;\n\t\tif(rank[x]<rank[y])par[x]=y;\n\
    \t\telse{\n\t\t\tpar[y]=x;\n\t\t\tif(rank[x]==rank[y])++rank[x];\n\t\t}\n\t}\n\
    };\n\n/**\n* @title Union Find\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/union-find.hpp
  requiredBy: []
  timestamp: '2020-06-22 16:37:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/union-find.test.cpp
documentation_of: lib/data-structure/union-find.hpp
layout: document
redirect_from:
- /library/lib/data-structure/union-find.hpp
- /library/lib/data-structure/union-find.hpp.html
title: Union Find
---
