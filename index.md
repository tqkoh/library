---
data:
  libraryCategories:
  - name: lib/data-structure
    pages:
    - icon: ':heavy_check_mark:'
      path: lib/data-structure/rangeadd-bit.hpp
      title: Rangeadd BIT
    - icon: ':warning:'
      path: lib/data-structure/splay-tree-set.hpp
      title: Splay Tree Set
    - icon: ':heavy_check_mark:'
      path: lib/data-structure/union-find.hpp
      title: Union Find
  - name: lib/gomi
    pages:
    - icon: ':warning:'
      path: lib/gomi/lattice-conv.hpp
      title: Lattice Conv
  - name: lib/graph
    pages:
    - icon: ':heavy_check_mark:'
      path: lib/graph/bfs.hpp
      title: BFS
    - icon: ':heavy_check_mark:'
      path: lib/graph/dijkstra.hpp
      title: Dijkstra
    - icon: ':heavy_check_mark:'
      path: lib/graph/graph-template.hpp
      title: Graph Template
    - icon: ':heavy_check_mark:'
      path: lib/graph/warshall-floyd.hpp
      title: Warshall Floyd
  - name: lib/util
    pages:
    - icon: ':heavy_check_mark:'
      path: lib/util/divisors.hpp
      title: Divisors
    - icon: ':warning:'
      path: lib/util/eratosthenes.hpp
      title: Eratosthenes
    - icon: ':warning:'
      path: lib/util/mint.hpp
      title: Mint
    - icon: ':warning:'
      path: lib/util/ncr-or.hpp
      title: Ncr Or
    - icon: ':warning:'
      path: lib/util/ncr.hpp
      title: Ncr
  - name: test/template
    pages:
    - icon: ':heavy_check_mark:'
      path: test/template/template.hpp
      title: test/template/template.hpp
  - name: tools
    pages:
    - icon: ':warning:'
      path: tools/docs.py
      title: tools/docs.py
  verificationCategories:
  - name: test/data-structure
    pages:
    - icon: ':heavy_check_mark:'
      path: test/data-structure/rangeadd-bit.test.cpp
      title: test/data-structure/rangeadd-bit.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/data-structure/union-find.test.cpp
      title: test/data-structure/union-find.test.cpp
  - name: test/graph
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/bfs.test.cpp
      title: test/graph/bfs.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/graph/dijkstra.test.cpp
      title: test/graph/dijkstra.test.cpp
    - icon: ':heavy_check_mark:'
      path: test/graph/warshall-floyd.test.cpp
      title: test/graph/warshall-floyd.test.cpp
  - name: test/util
    pages:
    - icon: ':heavy_check_mark:'
      path: test/util/divisors.test.cpp
      title: test/util/divisors.test.cpp
layout: toppage
---
## めもs
- tqk がスニペットとして使ってるライブラリたち
  - [自分用競プロツール](https://github.com/tqkoh/ac)で手元スニペットを更新 競プロディレクトリから`$ mksnip`
- `gomi` とそれ以外にカテゴリ分けする
  - `gomi`: 
    - そのままスニペットになるもの。時短など
    - 記法:
      - `#define IGNORE` を書く
      - `#literal nanka` で nanka という置き換えを作れる。
      - 本文中で `$nanka$` と書くことで、貼り付け時に `$nanka$` 全てを置換できる
  - それ以外: 
    - class などとして global な場所に置くもの。アやデなど
