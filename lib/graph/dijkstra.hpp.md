---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/dijkstra.test.cpp
    title: test/graph/dijkstra.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"lib/graph/dijkstra.hpp\"\n// struct status{\n// \tlint dist;\n\
    // \tstatus(lint n){\n// \t\tif(!n)dist=0; //initial\n// \t\telse dist=linf; //infinity\n\
    // \t}\n// };\n// constexpr bool operator<(const status& lhs,const status& rhs){\n\
    // \treturn lhs.dist<rhs.dist;\n// }\n// status operator+(status cur,length& cost){\n\
    // \tcur.dist+=cost;\n// \treturn cur;\n// }\n\n// pair<vector<status>,vector<int>>\
    \ dijkstra(Weighted g,int s){\n// \tvector<int> prv(g.size());\n// \tvector<status>\
    \ d(g.size(),linf);\n// \tusing cont=pair<status,int>;\n// \tpriority_queue<cont,vector<cont>,greater<cont>\
    \ > q;\n\n// \td[s]=0;q.push({0,s});\n// \twhile(q.size()){\n// \t\tstatus cd=q.top().first;\n\
    // \t\tint cv=q.top().second;\n// \t\tq.pop();\n// \t\tif(d[cv]<cd)continue;\n\
    // \t\tfor(edge& e:g[cv])if(cd+e.cost<d[e.to]){\n// \t\t\td[e.to]=cd+e.cost;\n\
    // \t\t\tprv[e.to]=cv;\n// \t\t\tq.push({d[e.to],e.to});\n// \t\t}\n// \t}\n//\
    \ \treturn {d,prv};\n// }\n\n/*\n* @title Dijkstra\n* @docs docs/graph/dijkstra.md\n\
    */\n"
  code: "#pragma once\n// struct status{\n// \tlint dist;\n// \tstatus(lint n){\n\
    // \t\tif(!n)dist=0; //initial\n// \t\telse dist=linf; //infinity\n// \t}\n//\
    \ };\n// constexpr bool operator<(const status& lhs,const status& rhs){\n// \t\
    return lhs.dist<rhs.dist;\n// }\n// status operator+(status cur,length& cost){\n\
    // \tcur.dist+=cost;\n// \treturn cur;\n// }\n\n// pair<vector<status>,vector<int>>\
    \ dijkstra(Weighted g,int s){\n// \tvector<int> prv(g.size());\n// \tvector<status>\
    \ d(g.size(),linf);\n// \tusing cont=pair<status,int>;\n// \tpriority_queue<cont,vector<cont>,greater<cont>\
    \ > q;\n\n// \td[s]=0;q.push({0,s});\n// \twhile(q.size()){\n// \t\tstatus cd=q.top().first;\n\
    // \t\tint cv=q.top().second;\n// \t\tq.pop();\n// \t\tif(d[cv]<cd)continue;\n\
    // \t\tfor(edge& e:g[cv])if(cd+e.cost<d[e.to]){\n// \t\t\td[e.to]=cd+e.cost;\n\
    // \t\t\tprv[e.to]=cv;\n// \t\t\tq.push({d[e.to],e.to});\n// \t\t}\n// \t}\n//\
    \ \treturn {d,prv};\n// }\n\n/*\n* @title Dijkstra\n* @docs docs/graph/dijkstra.md\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-11-09 11:33:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/dijkstra.test.cpp
documentation_of: lib/graph/dijkstra.hpp
layout: document
redirect_from:
- /library/lib/graph/dijkstra.hpp
- /library/lib/graph/dijkstra.hpp.html
title: Dijkstra
---
# 説明
- 負辺のないグラフ g に対して、(s から各頂点への最短パスの長さ, 前の頂点)を求める

# 時間計算量
- O(E log V)
