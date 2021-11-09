---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data-structure/rangeadd-bit.test.cpp
    title: test/data-structure/rangeadd-bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: RangeAdd Binary Indexed Tree
    links: []
  bundledCode: "#line 2 \"lib/data-structure/rangeadd-bit.hpp\"\ntemplate<typename\
    \ T>\nclass BIT{\npublic:\n\tvector<T> b,a;\n\tBIT(int sz){ sz+=2;a.assign(sz,0);b.assign(sz,0);\
    \ }\n\tvoid updateAB(int k,T na,T nb){\n\t\tfor(;k<a.size();k+=k&-k){\n\t\t\t\
    a[k]+=na;\n\t\t\tb[k]+=nb;\n\t\t}\n\t}\n\tT query(int k){\n\t\tT A=0;\n\t\tT B=0;\n\
    \t\tint start=k;\n\t\tfor(;k>0;k-=k&-k){\n\t\t\tA += a[k];\n\t\t\tB += b[k];\n\
    \t\t}\n\t\treturn A*--start+B;\n\t}\n\tvoid add(int l,int r,T x){\n\t\tupdateAB(l,x,-x*(l-1));\n\
    \t\tupdateAB(r,-x,x*(r-1));\n\t}\n\tT sum(int l,int r){\n\t\treturn query(r)-query(l);\n\
    \t}\n};\n\n/*\n* @title RangeAdd Binary Indexed Tree\n*/\n"
  code: "#pragma once\ntemplate<typename T>\nclass BIT{\npublic:\n\tvector<T> b,a;\n\
    \tBIT(int sz){ sz+=2;a.assign(sz,0);b.assign(sz,0); }\n\tvoid updateAB(int k,T\
    \ na,T nb){\n\t\tfor(;k<a.size();k+=k&-k){\n\t\t\ta[k]+=na;\n\t\t\tb[k]+=nb;\n\
    \t\t}\n\t}\n\tT query(int k){\n\t\tT A=0;\n\t\tT B=0;\n\t\tint start=k;\n\t\t\
    for(;k>0;k-=k&-k){\n\t\t\tA += a[k];\n\t\t\tB += b[k];\n\t\t}\n\t\treturn A*--start+B;\n\
    \t}\n\tvoid add(int l,int r,T x){\n\t\tupdateAB(l,x,-x*(l-1));\n\t\tupdateAB(r,-x,x*(r-1));\n\
    \t}\n\tT sum(int l,int r){\n\t\treturn query(r)-query(l);\n\t}\n};\n\n/*\n* @title\
    \ RangeAdd Binary Indexed Tree\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/data-structure/rangeadd-bit.hpp
  requiredBy: []
  timestamp: '2020-08-11 13:42:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data-structure/rangeadd-bit.test.cpp
documentation_of: lib/data-structure/rangeadd-bit.hpp
layout: document
redirect_from:
- /library/lib/data-structure/rangeadd-bit.hpp
- /library/lib/data-structure/rangeadd-bit.hpp.html
title: RangeAdd Binary Indexed Tree
---
