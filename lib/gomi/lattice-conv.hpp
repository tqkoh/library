#define IGNORE
#literal z
#literal uz
auto $z$ = [&](P p)->int{ return p.f*w+p.s; };
auto $uz$ = [&](int c)->P{ return P(c/w, c%w); };
