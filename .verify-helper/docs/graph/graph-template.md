---
title: Graph Template
documentation_of: //lib/graph/graph-template.hpp
---

# 説明

## length
- lint
- 長さ。前は edge の最後を length cost にして型をいじっていたがやり方を変えた(後述)
- Matrix 用に残してるけどイランかも

## edge
- `struct{ int src, to, id; }`
- 辺。(src, to, id) は (始点、終点、辺番号(問題文で与えられる順番など))
- cost は、代わりに辺番号を持つ。
- 例えば問題文で辺の (src, to, 辺の長さ) が (a[i], b[i], c[i]) として与えられるなら、辺 e の長さは c[e.id] と表す
- 辺がいくつ情報を持っていても nanka[e.id] で表せるのでこの中身を触る必要はない

## Graph
- `vector<vector<edge>>`
- 隣接リスト。なんでかわからんけど 'G'raph と 'e'dge がしっくりくる
- add_edge(src, to, (id), (directed)): 辺追加
  - directed: 有向なら 1 そうでなければ 0

## Matrix
- `vector<vector<length>>`
- 隣接行列。warshall-floyd のみ?
- add_edge(src, to, (cost), (directed)): 辺追加
  - directed: 有向なら 1 そうでなければ 0
