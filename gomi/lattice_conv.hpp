#literal g
Weighted $g$(h*w);
rep(h)rep(j, w-1)if(s[i][j]!='#'&&s[i][j+1]!='#')$g$.add_edge(z(i, j), z(i, j+1));
rep(h-1)rep(j, w)if(s[i][j]!='#'&&s[i+1][j]!='#')$g$.add_edge(z(i, j), z(i+1, j));
