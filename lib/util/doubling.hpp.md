---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/doubling.test.cpp
    title: test/util/doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Doubling
    links: []
  bundledCode: "#line 2 \"lib/util/doubling.hpp\"\n\nclass Doubling{\npublic:\n\t\
    vector<vector<lint>>d;\n\tlint l = 0;\n\tDoubling(vector<lint>f, lint maxpow =\
    \ -1){\n\t\tif(maxpow<0)maxpow = f.size();\n\t\tl = log2(maxpow)+1;\n\t\td.resize(l,\
    \ f);\n\t\tfor(int p = 0; p<l-1; ++p)for(int i=0; i<f.size(); ++i)d[p+1][i] =\
    \ d[p][d[p][i]];\n\t}\n\tlint operator()(lint pow, lint i){\n\t\tfor(lint j =\
    \ 0; pow; ++j){\n\t\t\tif(pow%2)i = d[j][i];\n\t\t\tpow >>= 1;\n\t\t}\n\t\treturn\
    \ i;\n\t}\n};\n\n/*\n* @title Doubling\n*/\n"
  code: "#pragma once\n\nclass Doubling{\npublic:\n\tvector<vector<lint>>d;\n\tlint\
    \ l = 0;\n\tDoubling(vector<lint>f, lint maxpow = -1){\n\t\tif(maxpow<0)maxpow\
    \ = f.size();\n\t\tl = log2(maxpow)+1;\n\t\td.resize(l, f);\n\t\tfor(int p = 0;\
    \ p<l-1; ++p)for(int i=0; i<f.size(); ++i)d[p+1][i] = d[p][d[p][i]];\n\t}\n\t\
    lint operator()(lint pow, lint i){\n\t\tfor(lint j = 0; pow; ++j){\n\t\t\tif(pow%2)i\
    \ = d[j][i];\n\t\t\tpow >>= 1;\n\t\t}\n\t\treturn i;\n\t}\n};\n\n/*\n* @title\
    \ Doubling\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/doubling.hpp
  requiredBy: []
  timestamp: '2021-11-11 17:13:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/doubling.test.cpp
documentation_of: lib/util/doubling.hpp
layout: document
redirect_from:
- /library/lib/util/doubling.hpp
- /library/lib/util/doubling.hpp.html
title: Doubling
---
