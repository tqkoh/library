---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"lib/graph/graph-template.hpp\"\nusing length=lint;\nstruct\
    \ edge{\n\tint src,to;\n\tlength cost;\n\tedge()=default;\n\tedge(int src,int\
    \ to,length cost): src(src),to(to),cost(cost){}\n};\n\nusing Edges=vector<edge>;\n\
    using Weighted=vector<Edges>;\nusing UnWeighted=vector<vector<int> >;\nusing Matrix=vector<vector<length>\
    \ >;\n\nvoid e2w(Weighted& g,Edges edges,bool directed){\n\tfor(auto& e:edges){\n\
    \t\tg[e.src].push_back(e);\n\t\tif(!directed)g[e.to].push_back(edge(e.to,e.src,e.cost));\n\
    \t}\n}\nvoid e2u(UnWeighted& g,Edges edges,bool directed){\n\tfor(auto& e:edges){\n\
    \t\tg[e.src].push_back(e.to);\n\t\tif(!directed)g[e.to].push_back(e.src);\n\t\
    }\n}\nvoid e2m(Matrix& g,Edges edges,bool directed,length infinity){\n\tfor(auto&\
    \ e:g)e.resize(g.size(),infinity);\n\tfor(int i=0;i<g.size();++i)g[i][i]=0;\n\t\
    for(auto& e:edges){\n\t\tg[e.src][e.to]=min(g[e.src][e.to],e.cost);\n\t\tif(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);\n\
    \t}\n}\n\n\n/*\n* @title Graph Template\n*/\n"
  code: "#pragma once\nusing length=lint;\nstruct edge{\n\tint src,to;\n\tlength cost;\n\
    \tedge()=default;\n\tedge(int src,int to,length cost): src(src),to(to),cost(cost){}\n\
    };\n\nusing Edges=vector<edge>;\nusing Weighted=vector<Edges>;\nusing UnWeighted=vector<vector<int>\
    \ >;\nusing Matrix=vector<vector<length> >;\n\nvoid e2w(Weighted& g,Edges edges,bool\
    \ directed){\n\tfor(auto& e:edges){\n\t\tg[e.src].push_back(e);\n\t\tif(!directed)g[e.to].push_back(edge(e.to,e.src,e.cost));\n\
    \t}\n}\nvoid e2u(UnWeighted& g,Edges edges,bool directed){\n\tfor(auto& e:edges){\n\
    \t\tg[e.src].push_back(e.to);\n\t\tif(!directed)g[e.to].push_back(e.src);\n\t\
    }\n}\nvoid e2m(Matrix& g,Edges edges,bool directed,length infinity){\n\tfor(auto&\
    \ e:g)e.resize(g.size(),infinity);\n\tfor(int i=0;i<g.size();++i)g[i][i]=0;\n\t\
    for(auto& e:edges){\n\t\tg[e.src][e.to]=min(g[e.src][e.to],e.cost);\n\t\tif(!directed)g[e.to][e.src]=min(g[e.to][e.src],e.cost);\n\
    \t}\n}\n\n\n/*\n* @title Graph Template\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/graph-template.hpp
  requiredBy: []
  timestamp: '2020-06-22 16:37:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
