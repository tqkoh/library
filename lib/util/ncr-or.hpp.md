---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Ncr O(r)
    links: []
  bundledCode: "#line 2 \"lib/util/ncr-or.hpp\"\ntemplate<class Int,uint_fast64_t\
    \ md=mod>\nInt ncr(lint n,lint r){\n\tif(n<r||n<0||r<0)return Int(0);\n\tInt ncr_res=1,ncr_div=1;\n\
    \tfor(int i=0; i<r; ++i)ncr_res*=(n-i),ncr_div*=(r-i);\n\treturn ncr_res/ncr_div;\n\
    }\n\n/*\n* @title Ncr O(r)\n*/\n"
  code: "#pragma once\ntemplate<class Int,uint_fast64_t md=mod>\nInt ncr(lint n,lint\
    \ r){\n\tif(n<r||n<0||r<0)return Int(0);\n\tInt ncr_res=1,ncr_div=1;\n\tfor(int\
    \ i=0; i<r; ++i)ncr_res*=(n-i),ncr_div*=(r-i);\n\treturn ncr_res/ncr_div;\n}\n\
    \n/*\n* @title Ncr O(r)\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/util/ncr-or.hpp
  requiredBy: []
  timestamp: '2020-06-22 16:37:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/ncr-or.hpp
layout: document
title: Ncr Or
---
