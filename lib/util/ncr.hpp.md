---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: lib/util/mint.hpp
    title: Mint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Ncr
    links: []
  bundledCode: "#line 2 \"lib/util/mint.hpp\"\n#define md_tmp template<uint_fast64_t\
    \ md=mod>\nmd_tmp class modint{\n\tusing u64=uint_fast64_t;\n\npublic:\n\tu64\
    \ a;\n\n\tconstexpr modint(const lint x=0) noexcept: a((x+md)%md){}\n\tconstexpr\
    \ u64 &value() noexcept{ return a; }\n\tconstexpr const u64 &value() const noexcept{\
    \ return a; }\n\tconstexpr modint operator+(const modint rhs) const noexcept{\n\
    \t\treturn modint(*this)+=rhs;\n\t}\n\tconstexpr modint operator-(const modint\
    \ rhs) const noexcept{\n\t\treturn modint(*this)-=rhs;\n\t}\n\tconstexpr modint\
    \ operator*(const modint rhs) const noexcept{\n\t\treturn modint(*this)*=rhs;\n\
    \t}\n\tconstexpr modint operator^(const lint rhs) const noexcept{\n\t\treturn\
    \ modint(*this)^=rhs;\n\t}\n\tconstexpr modint operator/(const modint rhs) const\
    \ noexcept{\n\t\treturn modint(*this)/=rhs;\n\t}\n\tconstexpr modint &operator+=(const\
    \ modint rhs) noexcept{\n\t\ta+=rhs.a;\n\t\tif(a>=md)a-=md;\n\t\treturn *this;\n\
    \t}\n\tconstexpr modint &operator-=(const modint rhs) noexcept{\n\t\tif(a<rhs.a)a+=md;\n\
    \t\ta-=rhs.a;\n\t\treturn *this;\n\t}\n\tconstexpr modint &operator*=(const modint\
    \ rhs) noexcept{\n\t\ta=a*rhs.a%md;\n\t\treturn *this;\n\t}\n\tconstexpr modint\
    \ &operator^=(const lint rhs) noexcept{\n\t\tif(!rhs)return *this = 1;\n\t\tu64\
    \ exp=rhs-1;\n\t\tmodint base=a;\n\t\twhile(exp){\n\t\t\tif(exp&1)*this*=base;\n\
    \t\t\tbase*=base;\n\t\t\texp>>=1;\n\t\t}\n\t\treturn *this;\n\t}\n\tconstexpr\
    \ modint &operator/=(const modint rhs) noexcept{\n\t\ta=(*this*(rhs^(md-2))).a;\n\
    \t\treturn *this;\n\t}\n};\nmd_tmp istream& operator>>(istream& os,modint<md>&\
    \ m){\n\tos>>m.a,m.a%=md;\n\treturn os;\n}\nmd_tmp ostream& operator<<(ostream&\
    \ os,const modint<md>& m){\n\treturn os<<m.a;\n}\nusing mint = modint<>;\n//#ifndef\
    \ _AOJ_\n//mint operator\"\"m(unsigned long long n){ return mint(n); }\n//#endif\n\
    \n/*\n* @title Mint\n* @see https://noshi91.hatenablog.com/entry/2019/03/31/174006\n\
    */\n#line 3 \"lib/util/ncr.hpp\"\n#define MAXN 10000010\nmd_tmp class Ncr{\n\t\
    lint m;\npublic:\n\tmint fa[MAXN],rfa[MAXN];\n\tNcr(lint n):m(n){\n\t\tfa[0]=1;\n\
    \t\tfor(int i=1; i<m; ++i)fa[i]=(fa[i-1]*i);\n\t\trfa[m-1]=mint(1)/fa[m-1];\n\t\
    \tfor(int i=m-2; i>=0; --i)rfa[i]=rfa[i+1]*(i+1);\n\t}\n\tinline mint ncr(lint\
    \ n,lint r){ if(n<r||n<0||r<0)return 0m; return(fa[n]*rfa[r]*rfa[n-r]); }\n};\n\
    Ncr<> c(MAXN);\n#undef MAXN\n\n/*\n* @title Ncr\n*/\n"
  code: "#pragma once\n#include \"../../lib/util/mint.hpp\"\n#define MAXN 10000010\n\
    md_tmp class Ncr{\n\tlint m;\npublic:\n\tmint fa[MAXN],rfa[MAXN];\n\tNcr(lint\
    \ n):m(n){\n\t\tfa[0]=1;\n\t\tfor(int i=1; i<m; ++i)fa[i]=(fa[i-1]*i);\n\t\trfa[m-1]=mint(1)/fa[m-1];\n\
    \t\tfor(int i=m-2; i>=0; --i)rfa[i]=rfa[i+1]*(i+1);\n\t}\n\tinline mint ncr(lint\
    \ n,lint r){ if(n<r||n<0||r<0)return 0m; return(fa[n]*rfa[r]*rfa[n-r]); }\n};\n\
    Ncr<> c(MAXN);\n#undef MAXN\n\n/*\n* @title Ncr\n*/\n"
  dependsOn:
  - lib/util/mint.hpp
  isVerificationFile: false
  path: lib/util/ncr.hpp
  requiredBy: []
  timestamp: '2020-08-11 13:42:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/util/ncr.hpp
layout: document
title: Ncr
---
