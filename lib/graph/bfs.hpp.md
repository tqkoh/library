---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: bfs
    links: []
  bundledCode: "#line 2 \"lib/graph/bfs.hpp\"\ntemplate<class viFi, class vFe >\n\
    void bfs(int n, int s, viFi next, vFe dtmn){\n\tvector<int>vis(n);\n\tqueue<int>q({\
    \ s });\n\twhile(q.size()){\n\t\tint c = q.front(); q.pop();\n\t\tif(vis[c])continue;\n\
    \t\tvis[c] = 1;\n\t\teach(next(c))if(!vis[e.to])dtmn(e), q.push(e.to);\n\t}\n\
    }\n\n/*\n* @title bfs\n*/\n"
  code: "#pragma once\ntemplate<class viFi, class vFe >\nvoid bfs(int n, int s, viFi\
    \ next, vFe dtmn){\n\tvector<int>vis(n);\n\tqueue<int>q({ s });\n\twhile(q.size()){\n\
    \t\tint c = q.front(); q.pop();\n\t\tif(vis[c])continue;\n\t\tvis[c] = 1;\n\t\t\
    each(next(c))if(!vis[e.to])dtmn(e), q.push(e.to);\n\t}\n}\n\n/*\n* @title bfs\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/graph/bfs.hpp
  requiredBy: []
  timestamp: '2021-11-09 11:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/bfs.hpp
layout: document
redirect_from:
- /library/lib/graph/bfs.hpp
- /library/lib/graph/bfs.hpp.html
title: bfs
---
