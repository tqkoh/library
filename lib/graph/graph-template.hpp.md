---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/bfs.test.cpp
    title: test/graph/bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall-floyd.test.cpp
    title: test/graph/warshall-floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Graph Template
    links: []
  bundledCode: "#line 2 \"lib/graph/graph-template.hpp\"\nusing length = lint;\nstruct\
    \ edge{\n\tint src, to, id;\n\tedge() = default;\n\tedge(int src, int to, int\
    \ id = 0): src(src), to(to), id(id){}\n};\n\nusing Edges = vector<edge>;\nclass\
    \ Graph: public vector<Edges>{\npublic:\n\tGraph(int n){\n\t\tthis->resize(n);\n\
    \t}\n\tvoid add_edge(edge e, bool directed = 0){\n\t\t(*this)[e.src].push_back(e);\n\
    \t\tif(!directed)(*this)[e.to].push_back(edge(e.to, e.src, e.id));\n\t}\n\tvoid\
    \ add_edge(int src, int to, int id = 0, bool directed = 0){\n\t\t(*this)[src].push_back(edge(src,\
    \ to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to, src, id));\n\t}\n\
    };\nclass Matrix: public vector<vector<length>>{\npublic:\n\tMatrix(int n, length\
    \ inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\t\tfor(int i\
    \ = 0; i<n; ++i)(*this)[i][i] = 0;\n\t}\n\tvoid add_edge(edge e, length cost,\
    \ bool directed = 0){\n\t\tif((*this)[e.src][e.to]>cost)(*this)[e.src][e.to] =\
    \ cost;\n\t\tif(!directed)if((*this)[e.to][e.src]>cost)(*this)[e.to][e.src] =\
    \ cost;\n\t}\n\tvoid add_edge(int src, int to, length cost, bool directed = 0){\n\
    \t\tif((*this)[src][to]>cost)(*this)[src][to] = cost;\n\t\tif(!directed)if((*this)[to][src]>cost)(*this)[to][src]\
    \ = cost;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n"
  code: "#pragma once\nusing length = lint;\nstruct edge{\n\tint src, to, id;\n\t\
    edge() = default;\n\tedge(int src, int to, int id = 0): src(src), to(to), id(id){}\n\
    };\n\nusing Edges = vector<edge>;\nclass Graph: public vector<Edges>{\npublic:\n\
    \tGraph(int n){\n\t\tthis->resize(n);\n\t}\n\tvoid add_edge(edge e, bool directed\
    \ = 0){\n\t\t(*this)[e.src].push_back(e);\n\t\tif(!directed)(*this)[e.to].push_back(edge(e.to,\
    \ e.src, e.id));\n\t}\n\tvoid add_edge(int src, int to, int id = 0, bool directed\
    \ = 0){\n\t\t(*this)[src].push_back(edge(src, to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to,\
    \ src, id));\n\t}\n};\nclass Matrix: public vector<vector<length>>{\npublic:\n\
    \tMatrix(int n, length inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\
    \t\tfor(int i = 0; i<n; ++i)(*this)[i][i] = 0;\n\t}\n\tvoid add_edge(edge e, length\
    \ cost, bool directed = 0){\n\t\tif((*this)[e.src][e.to]>cost)(*this)[e.src][e.to]\
    \ = cost;\n\t\tif(!directed)if((*this)[e.to][e.src]>cost)(*this)[e.to][e.src]\
    \ = cost;\n\t}\n\tvoid add_edge(int src, int to, length cost, bool directed =\
    \ 0){\n\t\tif((*this)[src][to]>cost)(*this)[src][to] = cost;\n\t\tif(!directed)if((*this)[to][src]>cost)(*this)[to][src]\
    \ = cost;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-template.hpp
  requiredBy: []
  timestamp: '2021-11-09 20:40:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/bfs.test.cpp
  - test/graph/warshall-floyd.test.cpp
documentation_of: lib/graph/graph-template.hpp
layout: document
title: Graph Template
---

## 説明

### length
- lint
- 長さ。前は edge の最後を length cost にして型をいじっていたがやり方を変えた(後述)
- Matrix 用に残してるけどイランかも

### edge
- `struct{ int src, to, id; }`
- 辺。(src, to, id) は (始点、終点、辺番号(問題文で与えられる順番など))
- cost は、代わりに辺番号を持つ。
- 例えば問題文で辺の (src, to, 辺の長さ) が (a[i], b[i], c[i]) として与えられるなら、辺 e の長さは c[e.id] と表す
- 辺がいくつ情報を持っていても nanka[e.id] で表せるのでこの中身を触る必要はない

### Graph
- `vector<vector<edge>>`
- 隣接リスト。なんでかわからんけど 'G'raph と 'e'dge がしっくりくる
- add_edge(src, to, (id), (directed)): 辺追加
  - directed: 有向なら 1 そうでなければ 0

### Matrix
- `vector<vector<length>>`
- 隣接行列。warshall-floyd のみ?
- add_edge(src, to, (cost), (directed)): 辺追加
  - directed: 有向なら 1 そうでなければ 0
