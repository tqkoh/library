---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall-floyd.test.cpp
    title: test/graph/warshall-floyd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Warshall Floyd
    links: []
  bundledCode: "#line 2 \"lib/graph/warshall-floyd.hpp\"\nint warshall_floyd(Matrix&\
    \ g, length inf = 2*linf){\n\tint n = g.size();\n\tfor(int k = 0; k<n; ++k){\n\
    \t\tfor(int i = 0; i<n; ++i){\n\t\t\tfor(int j = 0; j<n; ++j){\n\t\t\t\tif(g[i][k]==inf||g[k][j]==inf)continue;\n\
    \t\t\t\tg[i][j] = min(g[i][j], g[i][k]+g[k][j]);\n\t\t\t}\n\t\t}\n\t}\n\tfor(int\
    \ i = 0; i<n; ++i){\n\t\tif(g[i][i]<0)return 1;\n\t}\n\treturn 0;\n}\n/*\n* @title\
    \ Warshall Floyd\n* @brief returns 1 if negative cycle exists\n*/\n"
  code: "#pragma once\nint warshall_floyd(Matrix& g, length inf = 2*linf){\n\tint\
    \ n = g.size();\n\tfor(int k = 0; k<n; ++k){\n\t\tfor(int i = 0; i<n; ++i){\n\t\
    \t\tfor(int j = 0; j<n; ++j){\n\t\t\t\tif(g[i][k]==inf||g[k][j]==inf)continue;\n\
    \t\t\t\tg[i][j] = min(g[i][j], g[i][k]+g[k][j]);\n\t\t\t}\n\t\t}\n\t}\n\tfor(int\
    \ i = 0; i<n; ++i){\n\t\tif(g[i][i]<0)return 1;\n\t}\n\treturn 0;\n}\n/*\n* @title\
    \ Warshall Floyd\n* @brief returns 1 if negative cycle exists\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2021-11-09 16:09:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshall-floyd.test.cpp
documentation_of: lib/graph/warshall-floyd.hpp
layout: document
title: Warshall Floyd
---
