---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/warshall-floyd.test.cpp
    title: test/graph/warshall-floyd.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Warshall Floyd
    links: []
  bundledCode: "#line 2 \"lib/graph/warshall-floyd.hpp\"\nvoid warshall_floyd(Matrix\
    \ &g,length inf){\n\tfor(int k=0;k<g.size();++k){\n\t\tfor(int i=0;i<g.size();++i){\n\
    \t\t\tfor(int j=0;j<g.size();++j){\n\t\t\t\tif(g[i][k]==inf||g[k][j]==inf)continue;\n\
    \t\t\t\tg[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n\t\t\t}\n\t\t}\n\t}\n}\n/*\n* @title\
    \ Warshall Floyd\n*/\n"
  code: "#pragma once\nvoid warshall_floyd(Matrix &g,length inf){\n\tfor(int k=0;k<g.size();++k){\n\
    \t\tfor(int i=0;i<g.size();++i){\n\t\t\tfor(int j=0;j<g.size();++j){\n\t\t\t\t\
    if(g[i][k]==inf||g[k][j]==inf)continue;\n\t\t\t\tg[i][j]=min(g[i][j],g[i][k]+g[k][j]);\n\
    \t\t\t}\n\t\t}\n\t}\n}\n/*\n* @title Warshall Floyd\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2020-06-22 16:37:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/warshall-floyd.test.cpp
documentation_of: lib/graph/warshall-floyd.hpp
layout: document
redirect_from:
- /library/lib/graph/warshall-floyd.hpp
- /library/lib/graph/warshall-floyd.hpp.html
title: Warshall Floyd
---
