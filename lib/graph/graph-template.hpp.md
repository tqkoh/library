---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  - icon: ':x:'
    path: test/graph/warshall-floyd.test.cpp
    title: test/graph/warshall-floyd.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Graph Template
    links: []
  bundledCode: "#line 2 \"lib/graph/graph-template.hpp\"\nusing length = lint;\nstruct\
    \ edge{\n\tint src, to, id;\n\tedge() = default;\n\tedge(int src, int to, int\
    \ id = 0): src(src), to(to), id(id){}\n};\n\nusing Edges = vector<edge>;\nclass\
    \ Weighted: public vector<Edges>{\npublic:\n\tWeighted(int n){\n\t\tthis->resize(n);\n\
    \t}\n\tvoid add_edge(edge e, bool directed = 0){\n\t\t(*this)[e.src].push_back(e);\n\
    \t\tif(!directed)(*this)[e.to].push_back(edge(e.to, e.src, e.id));\n\t}\n\tvoid\
    \ add_edge(int src, int to, int id = 0, bool directed = 0){\n\t\t(*this)[src].push_back(edge(src,\
    \ to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to, src, id));\n\t}\n\
    };\nclass Matrix: public vector<vector<length>>{\npublic:\n\tMatrix(int n, length\
    \ inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\t\trep(n)(*this)[i][i]\
    \ = 0;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n\n\n/*\n* @title Graph Template\n\
    */\n"
  code: "#pragma once\nusing length = lint;\nstruct edge{\n\tint src, to, id;\n\t\
    edge() = default;\n\tedge(int src, int to, int id = 0): src(src), to(to), id(id){}\n\
    };\n\nusing Edges = vector<edge>;\nclass Weighted: public vector<Edges>{\npublic:\n\
    \tWeighted(int n){\n\t\tthis->resize(n);\n\t}\n\tvoid add_edge(edge e, bool directed\
    \ = 0){\n\t\t(*this)[e.src].push_back(e);\n\t\tif(!directed)(*this)[e.to].push_back(edge(e.to,\
    \ e.src, e.id));\n\t}\n\tvoid add_edge(int src, int to, int id = 0, bool directed\
    \ = 0){\n\t\t(*this)[src].push_back(edge(src, to, id));\n\t\tif(!directed)(*this)[to].push_back(edge(to,\
    \ src, id));\n\t}\n};\nclass Matrix: public vector<vector<length>>{\npublic:\n\
    \tMatrix(int n, length inf = 2*linf){\n\t\tthis->resize(n, vector<length>(n, inf));\n\
    \t\trep(n)(*this)[i][i] = 0;\n\t}\n};\n\n\n/*\n* @title Graph Template\n*/\n\n\
    \n/*\n* @title Graph Template\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-template.hpp
  requiredBy: []
  timestamp: '2021-11-09 11:33:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/dijkstra.test.cpp
  - test/graph/warshall-floyd.test.cpp
documentation_of: lib/graph/graph-template.hpp
layout: document
redirect_from:
- /library/lib/graph/graph-template.hpp
- /library/lib/graph/graph-template.hpp.html
title: Graph Template
---
