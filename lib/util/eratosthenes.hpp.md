---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: eratosthenes
    links: []
  bundledCode: "#line 2 \"lib/util/eratosthenes.hpp\"\nint cn[MAXN]; // prime:0\n\
    void erat(lint n){\n\tfor(int i=2; i<=n ++i){\n\t\tif(!cn[i]){\n\t\t\tfor(int\
    \ j=2*i; j<=n; j+=i)cn[j]=1;\n\t\t\t//i is prime\n\t\t}\n\t}\n}\n\n/*\n* @title\
    \ eratosthenes\n*/\n"
  code: "#pragma once\nint cn[MAXN]; // prime:0\nvoid erat(lint n){\n\tfor(int i=2;\
    \ i<=n ++i){\n\t\tif(!cn[i]){\n\t\t\tfor(int j=2*i; j<=n; j+=i)cn[j]=1;\n\t\t\t\
    //i is prime\n\t\t}\n\t}\n}\n\n/*\n* @title eratosthenes\n*/"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/eratosthenes.hpp
  requiredBy: []
  timestamp: '2020-06-25 18:07:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/eratosthenes.hpp
layout: document
redirect_from:
- /library/lib/util/eratosthenes.hpp
- /library/lib/util/eratosthenes.hpp.html
title: eratosthenes
---
