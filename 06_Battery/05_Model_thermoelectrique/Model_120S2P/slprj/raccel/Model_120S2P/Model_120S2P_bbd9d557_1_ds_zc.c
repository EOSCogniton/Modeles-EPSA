#include "__cf_Model_120S2P.h"
#include "ne_ds.h"
#include "Model_120S2P_bbd9d557_1_ds_zc.h"
#include "Model_120S2P_bbd9d557_1_ds_sys_struct.h"
#include "Model_120S2P_bbd9d557_1_ds_externals.h"
#include "Model_120S2P_bbd9d557_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Model_120S2P_bbd9d557_1_ds_zc ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ;
real_T t0 [ 241 ] ; real_T U [ 481 ] ; int32_T b ; for ( b = 0 ; b < 481 ; b
++ ) { U [ b ] = t1 -> mU . mX [ b ] ; } out = t2 -> mZC ; t0 [ 0ULL ] = U [
0ULL ] ; t0 [ 1ULL ] = U [ 2ULL ] ; t0 [ 2ULL ] = U [ 4ULL ] ; t0 [ 3ULL ] =
U [ 6ULL ] ; t0 [ 4ULL ] = U [ 8ULL ] ; t0 [ 5ULL ] = U [ 10ULL ] ; t0 [ 6ULL
] = U [ 12ULL ] ; t0 [ 7ULL ] = U [ 14ULL ] ; t0 [ 8ULL ] = U [ 16ULL ] ; t0
[ 9ULL ] = U [ 18ULL ] ; t0 [ 10ULL ] = U [ 20ULL ] ; t0 [ 11ULL ] = U [
22ULL ] ; t0 [ 12ULL ] = U [ 24ULL ] ; t0 [ 13ULL ] = U [ 26ULL ] ; t0 [
14ULL ] = U [ 28ULL ] ; t0 [ 15ULL ] = U [ 30ULL ] ; t0 [ 16ULL ] = U [ 32ULL
] ; t0 [ 17ULL ] = U [ 34ULL ] ; t0 [ 18ULL ] = U [ 36ULL ] ; t0 [ 19ULL ] =
U [ 38ULL ] ; t0 [ 20ULL ] = U [ 40ULL ] ; t0 [ 21ULL ] = U [ 42ULL ] ; t0 [
22ULL ] = U [ 44ULL ] ; t0 [ 23ULL ] = U [ 46ULL ] ; t0 [ 24ULL ] = U [ 48ULL
] ; t0 [ 25ULL ] = U [ 50ULL ] ; t0 [ 26ULL ] = U [ 52ULL ] ; t0 [ 27ULL ] =
U [ 54ULL ] ; t0 [ 28ULL ] = U [ 56ULL ] ; t0 [ 29ULL ] = U [ 58ULL ] ; t0 [
30ULL ] = U [ 60ULL ] ; t0 [ 31ULL ] = U [ 62ULL ] ; t0 [ 32ULL ] = U [ 64ULL
] ; t0 [ 33ULL ] = U [ 66ULL ] ; t0 [ 34ULL ] = U [ 68ULL ] ; t0 [ 35ULL ] =
U [ 70ULL ] ; t0 [ 36ULL ] = U [ 72ULL ] ; t0 [ 37ULL ] = U [ 74ULL ] ; t0 [
38ULL ] = U [ 76ULL ] ; t0 [ 39ULL ] = U [ 78ULL ] ; t0 [ 40ULL ] = U [ 80ULL
] ; t0 [ 41ULL ] = U [ 82ULL ] ; t0 [ 42ULL ] = U [ 84ULL ] ; t0 [ 43ULL ] =
U [ 86ULL ] ; t0 [ 44ULL ] = U [ 88ULL ] ; t0 [ 45ULL ] = U [ 90ULL ] ; t0 [
46ULL ] = U [ 92ULL ] ; t0 [ 47ULL ] = U [ 94ULL ] ; t0 [ 48ULL ] = U [ 96ULL
] ; t0 [ 49ULL ] = U [ 98ULL ] ; t0 [ 50ULL ] = U [ 100ULL ] ; t0 [ 51ULL ] =
U [ 102ULL ] ; t0 [ 52ULL ] = U [ 104ULL ] ; t0 [ 53ULL ] = U [ 106ULL ] ; t0
[ 54ULL ] = U [ 108ULL ] ; t0 [ 55ULL ] = U [ 110ULL ] ; t0 [ 56ULL ] = U [
112ULL ] ; t0 [ 57ULL ] = U [ 114ULL ] ; t0 [ 58ULL ] = U [ 116ULL ] ; t0 [
59ULL ] = U [ 118ULL ] ; t0 [ 60ULL ] = U [ 120ULL ] ; t0 [ 61ULL ] = U [
122ULL ] ; t0 [ 62ULL ] = U [ 124ULL ] ; t0 [ 63ULL ] = U [ 126ULL ] ; t0 [
64ULL ] = U [ 128ULL ] ; t0 [ 65ULL ] = U [ 130ULL ] ; t0 [ 66ULL ] = U [
132ULL ] ; t0 [ 67ULL ] = U [ 134ULL ] ; t0 [ 68ULL ] = U [ 136ULL ] ; t0 [
69ULL ] = U [ 138ULL ] ; t0 [ 70ULL ] = U [ 140ULL ] ; t0 [ 71ULL ] = U [
142ULL ] ; t0 [ 72ULL ] = U [ 144ULL ] ; t0 [ 73ULL ] = U [ 146ULL ] ; t0 [
74ULL ] = U [ 148ULL ] ; t0 [ 75ULL ] = U [ 150ULL ] ; t0 [ 76ULL ] = U [
152ULL ] ; t0 [ 77ULL ] = U [ 154ULL ] ; t0 [ 78ULL ] = U [ 156ULL ] ; t0 [
79ULL ] = U [ 158ULL ] ; t0 [ 80ULL ] = U [ 160ULL ] ; t0 [ 81ULL ] = U [
162ULL ] ; t0 [ 82ULL ] = U [ 164ULL ] ; t0 [ 83ULL ] = U [ 166ULL ] ; t0 [
84ULL ] = U [ 168ULL ] ; t0 [ 85ULL ] = U [ 170ULL ] ; t0 [ 86ULL ] = U [
172ULL ] ; t0 [ 87ULL ] = U [ 174ULL ] ; t0 [ 88ULL ] = U [ 176ULL ] ; t0 [
89ULL ] = U [ 178ULL ] ; t0 [ 90ULL ] = U [ 180ULL ] ; t0 [ 91ULL ] = U [
182ULL ] ; t0 [ 92ULL ] = U [ 184ULL ] ; t0 [ 93ULL ] = U [ 186ULL ] ; t0 [
94ULL ] = U [ 188ULL ] ; t0 [ 95ULL ] = U [ 190ULL ] ; t0 [ 96ULL ] = U [
192ULL ] ; t0 [ 97ULL ] = U [ 194ULL ] ; t0 [ 98ULL ] = U [ 196ULL ] ; t0 [
99ULL ] = U [ 198ULL ] ; t0 [ 100ULL ] = U [ 200ULL ] ; t0 [ 101ULL ] = U [
202ULL ] ; t0 [ 102ULL ] = U [ 204ULL ] ; t0 [ 103ULL ] = U [ 206ULL ] ; t0 [
104ULL ] = U [ 208ULL ] ; t0 [ 105ULL ] = U [ 210ULL ] ; t0 [ 106ULL ] = U [
212ULL ] ; t0 [ 107ULL ] = U [ 214ULL ] ; t0 [ 108ULL ] = U [ 216ULL ] ; t0 [
109ULL ] = U [ 218ULL ] ; t0 [ 110ULL ] = U [ 220ULL ] ; t0 [ 111ULL ] = U [
222ULL ] ; t0 [ 112ULL ] = U [ 224ULL ] ; t0 [ 113ULL ] = U [ 226ULL ] ; t0 [
114ULL ] = U [ 228ULL ] ; t0 [ 115ULL ] = U [ 230ULL ] ; t0 [ 116ULL ] = U [
232ULL ] ; t0 [ 117ULL ] = U [ 234ULL ] ; t0 [ 118ULL ] = U [ 236ULL ] ; t0 [
119ULL ] = U [ 238ULL ] ; t0 [ 120ULL ] = U [ 240ULL ] ; t0 [ 121ULL ] = U [
242ULL ] ; t0 [ 122ULL ] = U [ 244ULL ] ; t0 [ 123ULL ] = U [ 246ULL ] ; t0 [
124ULL ] = U [ 248ULL ] ; t0 [ 125ULL ] = U [ 250ULL ] ; t0 [ 126ULL ] = U [
252ULL ] ; t0 [ 127ULL ] = U [ 254ULL ] ; t0 [ 128ULL ] = U [ 256ULL ] ; t0 [
129ULL ] = U [ 258ULL ] ; t0 [ 130ULL ] = U [ 260ULL ] ; t0 [ 131ULL ] = U [
262ULL ] ; t0 [ 132ULL ] = U [ 264ULL ] ; t0 [ 133ULL ] = U [ 266ULL ] ; t0 [
134ULL ] = U [ 268ULL ] ; t0 [ 135ULL ] = U [ 270ULL ] ; t0 [ 136ULL ] = U [
272ULL ] ; t0 [ 137ULL ] = U [ 274ULL ] ; t0 [ 138ULL ] = U [ 276ULL ] ; t0 [
139ULL ] = U [ 278ULL ] ; t0 [ 140ULL ] = U [ 280ULL ] ; t0 [ 141ULL ] = U [
282ULL ] ; t0 [ 142ULL ] = U [ 284ULL ] ; t0 [ 143ULL ] = U [ 286ULL ] ; t0 [
144ULL ] = U [ 288ULL ] ; t0 [ 145ULL ] = U [ 290ULL ] ; t0 [ 146ULL ] = U [
292ULL ] ; t0 [ 147ULL ] = U [ 294ULL ] ; t0 [ 148ULL ] = U [ 296ULL ] ; t0 [
149ULL ] = U [ 298ULL ] ; t0 [ 150ULL ] = U [ 300ULL ] ; t0 [ 151ULL ] = U [
302ULL ] ; t0 [ 152ULL ] = U [ 304ULL ] ; t0 [ 153ULL ] = U [ 306ULL ] ; t0 [
154ULL ] = U [ 308ULL ] ; t0 [ 155ULL ] = U [ 310ULL ] ; t0 [ 156ULL ] = U [
312ULL ] ; t0 [ 157ULL ] = U [ 314ULL ] ; t0 [ 158ULL ] = U [ 316ULL ] ; t0 [
159ULL ] = U [ 318ULL ] ; t0 [ 160ULL ] = U [ 320ULL ] ; t0 [ 161ULL ] = U [
322ULL ] ; t0 [ 162ULL ] = U [ 324ULL ] ; t0 [ 163ULL ] = U [ 326ULL ] ; t0 [
164ULL ] = U [ 328ULL ] ; t0 [ 165ULL ] = U [ 330ULL ] ; t0 [ 166ULL ] = U [
332ULL ] ; t0 [ 167ULL ] = U [ 334ULL ] ; t0 [ 168ULL ] = U [ 336ULL ] ; t0 [
169ULL ] = U [ 338ULL ] ; t0 [ 170ULL ] = U [ 340ULL ] ; t0 [ 171ULL ] = U [
342ULL ] ; t0 [ 172ULL ] = U [ 344ULL ] ; t0 [ 173ULL ] = U [ 346ULL ] ; t0 [
174ULL ] = U [ 348ULL ] ; t0 [ 175ULL ] = U [ 350ULL ] ; t0 [ 176ULL ] = U [
352ULL ] ; t0 [ 177ULL ] = U [ 354ULL ] ; t0 [ 178ULL ] = U [ 356ULL ] ; t0 [
179ULL ] = U [ 358ULL ] ; t0 [ 180ULL ] = U [ 360ULL ] ; t0 [ 181ULL ] = U [
362ULL ] ; t0 [ 182ULL ] = U [ 364ULL ] ; t0 [ 183ULL ] = U [ 366ULL ] ; t0 [
184ULL ] = U [ 368ULL ] ; t0 [ 185ULL ] = U [ 370ULL ] ; t0 [ 186ULL ] = U [
372ULL ] ; t0 [ 187ULL ] = U [ 374ULL ] ; t0 [ 188ULL ] = U [ 376ULL ] ; t0 [
189ULL ] = U [ 378ULL ] ; t0 [ 190ULL ] = U [ 380ULL ] ; t0 [ 191ULL ] = U [
382ULL ] ; t0 [ 192ULL ] = U [ 384ULL ] ; t0 [ 193ULL ] = U [ 386ULL ] ; t0 [
194ULL ] = U [ 388ULL ] ; t0 [ 195ULL ] = U [ 390ULL ] ; t0 [ 196ULL ] = U [
392ULL ] ; t0 [ 197ULL ] = U [ 394ULL ] ; t0 [ 198ULL ] = U [ 396ULL ] ; t0 [
199ULL ] = U [ 398ULL ] ; t0 [ 200ULL ] = U [ 400ULL ] ; t0 [ 201ULL ] = U [
402ULL ] ; t0 [ 202ULL ] = U [ 404ULL ] ; t0 [ 203ULL ] = U [ 406ULL ] ; t0 [
204ULL ] = U [ 408ULL ] ; t0 [ 205ULL ] = U [ 410ULL ] ; t0 [ 206ULL ] = U [
412ULL ] ; t0 [ 207ULL ] = U [ 414ULL ] ; t0 [ 208ULL ] = U [ 416ULL ] ; t0 [
209ULL ] = U [ 418ULL ] ; t0 [ 210ULL ] = U [ 420ULL ] ; t0 [ 211ULL ] = U [
422ULL ] ; t0 [ 212ULL ] = U [ 424ULL ] ; t0 [ 213ULL ] = U [ 426ULL ] ; t0 [
214ULL ] = U [ 428ULL ] ; t0 [ 215ULL ] = U [ 430ULL ] ; t0 [ 216ULL ] = U [
432ULL ] ; t0 [ 217ULL ] = U [ 434ULL ] ; t0 [ 218ULL ] = U [ 436ULL ] ; t0 [
219ULL ] = U [ 438ULL ] ; t0 [ 220ULL ] = U [ 440ULL ] ; t0 [ 221ULL ] = U [
442ULL ] ; t0 [ 222ULL ] = U [ 444ULL ] ; t0 [ 223ULL ] = U [ 446ULL ] ; t0 [
224ULL ] = U [ 448ULL ] ; t0 [ 225ULL ] = U [ 450ULL ] ; t0 [ 226ULL ] = U [
452ULL ] ; t0 [ 227ULL ] = U [ 454ULL ] ; t0 [ 228ULL ] = U [ 456ULL ] ; t0 [
229ULL ] = U [ 458ULL ] ; t0 [ 230ULL ] = U [ 460ULL ] ; t0 [ 231ULL ] = U [
462ULL ] ; t0 [ 232ULL ] = U [ 464ULL ] ; t0 [ 233ULL ] = U [ 466ULL ] ; t0 [
234ULL ] = U [ 468ULL ] ; t0 [ 235ULL ] = U [ 470ULL ] ; t0 [ 236ULL ] = U [
472ULL ] ; t0 [ 237ULL ] = U [ 474ULL ] ; t0 [ 238ULL ] = U [ 476ULL ] ; t0 [
239ULL ] = U [ 478ULL ] ; t0 [ 240ULL ] = U [ 480ULL ] - 2.0 ; for ( b = 0 ;
b < 241 ; b ++ ) { out . mX [ b ] = t0 [ b ] ; } ( void ) sys ; ( void ) t2 ;
return 0 ; }
