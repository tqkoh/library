# Library 競プロライブラリ

# めも
- tqk がスニペットとして使ってるライブラリたち
  - [自分用競プロツール](https://github.com/tqkoh/ac)で更新 `mksnip`
- `gomi` とそれ以外にカテゴリ分けする
  - `gomi`: 
    - そのままスニペットになるもの。時短など
    - 記法は後述
  - それ以外: 
    - class などとして global な場所に置くもの。アやデなど

## gomi 記法
- スニペットとして貼り付けられるものを書く
- `#define IGNORE` を書く
- `#literal nanka` で nanka という置き換えが作れる。
- 本文中で `$nanka$` と書くことで、貼り付け時に `$nanka$` 全てを一括で置換できる
