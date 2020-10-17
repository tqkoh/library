---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/util/divisors.test.cpp
    title: test/util/divisors.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Divisors
    links: []
  bundledCode: "#line 2 \"lib/util/divisors.hpp\"\nset<lint>divisors(lint n){\n\t\
    set<lint>ret;\n\tfor(lint i=1; i*i<=n; ++i){\n\t\tif(n%i==0){\n\t\t\tret.insert(i);\n\
    \t\t\tif(i*i!=n)ret.insert(n/i);\n\t\t}\n\t}\n\treturn ret;\n}\n\n/*\n* @title\
    \ Divisors\n*/\n"
  code: "#pragma once\nset<lint>divisors(lint n){\n\tset<lint>ret;\n\tfor(lint i=1;\
    \ i*i<=n; ++i){\n\t\tif(n%i==0){\n\t\t\tret.insert(i);\n\t\t\tif(i*i!=n)ret.insert(n/i);\n\
    \t\t}\n\t}\n\treturn ret;\n}\n\n/*\n* @title Divisors\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/divisors.hpp
  requiredBy: []
  timestamp: '2020-10-18 00:44:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/util/divisors.test.cpp
documentation_of: lib/util/divisors.hpp
layout: document
redirect_from:
- /library/lib/util/divisors.hpp
- /library/lib/util/divisors.hpp.html
title: Divisors
---
