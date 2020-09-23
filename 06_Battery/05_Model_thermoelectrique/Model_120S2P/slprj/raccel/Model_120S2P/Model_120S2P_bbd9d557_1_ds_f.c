#include "__cf_Model_120S2P.h"
#include "ne_ds.h"
#include "Model_120S2P_bbd9d557_1_ds_f.h"
#include "Model_120S2P_bbd9d557_1_ds_sys_struct.h"
#include "Model_120S2P_bbd9d557_1_ds_externals.h"
#include "Model_120S2P_bbd9d557_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Model_120S2P_bbd9d557_1_ds_f ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t3 , NeDsMethodOutput * t4 ) { PmRealVector out ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm1_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm10_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm11_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm12_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm13_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm16_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm17_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm20_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm21_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm24_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm25_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm26_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm27_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm28_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm29_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm32_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm33_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm37_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm38_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm4_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm42_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm43_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm5_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm1_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm10_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm11_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm12_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm13_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm16_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm17_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm20_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm21_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm24_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm25_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm26_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm27_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm28_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm29_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm32_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm33_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm37_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm38_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm4_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm42_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm43_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm5_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm1_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm10_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm11_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm12_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm13_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm16_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm17_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm20_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm21_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm24_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm25_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm26_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm27_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm28_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm29_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm32_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm33_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm37_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm38_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm42_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm43_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm5_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm1_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm10_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm11_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm12_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm13_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm16_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm17_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm20_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm21_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm24_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm25_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm26_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm27_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm28_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm29_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm32_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm33_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm37_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm38_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm4_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm42_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm43_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm5_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm_Cell_R_inner_1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm1_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm10_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm11_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm12_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm13_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm16_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm17_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm20_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm21_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm24_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm25_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm26_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm27_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm28_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm29_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm32_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm33_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm37_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm38_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm4_Cell_R_inner1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm42_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm43_Cell_R_inne1 ;
real_T BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm5_Cell_R_inner1 ;
real_T BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i ; real_T t1 [ 593
] ; real_T t2 ; int32_T M [ 241 ] ; real_T U [ 481 ] ; real_T X [ 593 ] ;
int32_T b ; for ( b = 0 ; b < 241 ; b ++ ) { M [ b ] = t3 -> mM . mX [ b ] ;
} for ( b = 0 ; b < 481 ; b ++ ) { U [ b ] = t3 -> mU . mX [ b ] ; } for ( b
= 0 ; b < 593 ; b ++ ) { X [ b ] = t3 -> mX . mX [ b ] ; } out = t4 -> mF ;
t2 = ( - X [ 258ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm1_Cell_R_inner_1 = ( - X [
264ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm10_Cell_R_inner1 = ( - X [
268ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm11_Cell_R_inner1 = ( - X [
271ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm12_Cell_R_inner1 = ( - X [
275ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm13_Cell_R_inner1 = ( - X [
277ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm16_Cell_R_inner1 = ( - X [
281ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm17_Cell_R_inner1 = ( - X [
283ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm20_Cell_R_inner1 = ( - X [
288ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm21_Cell_R_inner1 = ( - X [
289ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm24_Cell_R_inner1 = ( - X [
293ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm25_Cell_R_inner1 = ( - X [
296ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm26_Cell_R_inner1 = ( - X [
299ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm27_Cell_R_inner1 = ( - X [
302ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm28_Cell_R_inner1 = ( - X [
305ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm29_Cell_R_inner1 = ( - X [
307ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm32_Cell_R_inner1 = ( - X [
309ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm33_Cell_R_inner1 = ( - X [
311ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm37_Cell_R_inner1 = ( - X [
313ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm38_Cell_R_inner1 = ( - X [
314ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm4_Cell_R_inner_1 = ( - X [
317ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm42_Cell_R_inner1 = ( - X [
318ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm43_Cell_R_inner1 = ( - X [
319ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm5_Cell_R_inner_1 = ( - X [
320ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm_Cell_R_inner_1 = ( - X [
340ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm1_Cell_R_inner1 = ( - X [
343ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm10_Cell_R_inne1 = ( - X [
346ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm11_Cell_R_inne1 = ( - X [
349ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm12_Cell_R_inne1 = ( - X [
352ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm13_Cell_R_inne1 = ( - X [
354ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm16_Cell_R_inne1 = ( - X [
356ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm17_Cell_R_inne1 = ( - X [
358ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm20_Cell_R_inne1 = ( - X [
360ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm21_Cell_R_inne1 = ( - X [
361ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm24_Cell_R_inne1 = ( - X [
364ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm25_Cell_R_inne1 = ( - X [
367ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm26_Cell_R_inne1 = ( - X [
370ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm27_Cell_R_inne1 = ( - X [
373ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm28_Cell_R_inne1 = ( - X [
376ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm29_Cell_R_inne1 = ( - X [
378ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm32_Cell_R_inne1 = ( - X [
380ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm33_Cell_R_inne1 = ( - X [
382ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm37_Cell_R_inne1 = ( - X [
384ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm38_Cell_R_inne1 = ( - X [
385ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm4_Cell_R_inner1 = ( - X [
387ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm42_Cell_R_inne1 = ( - X [
388ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm43_Cell_R_inne1 = ( - X [
389ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm5_Cell_R_inner1 = ( - X [
390ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm_Cell_R_inner_1 = ( - X [
408ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm1_Cell_R_inner1 = ( - X [
411ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm10_Cell_R_inne1 = ( - X [
414ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm11_Cell_R_inne1 = ( - X [
417ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm12_Cell_R_inne1 = ( - X [
420ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm13_Cell_R_inne1 = ( - X [
422ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm16_Cell_R_inne1 = ( - X [
424ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm17_Cell_R_inne1 = ( - X [
426ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm20_Cell_R_inne1 = ( - X [
428ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm21_Cell_R_inne1 = ( - X [
429ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm24_Cell_R_inne1 = ( - X [
432ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm25_Cell_R_inne1 = ( - X [
435ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm26_Cell_R_inne1 = ( - X [
438ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm27_Cell_R_inne1 = ( - X [
441ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm28_Cell_R_inne1 = ( - X [
444ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm29_Cell_R_inne1 = ( - X [
446ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm32_Cell_R_inne1 = ( - X [
448ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm33_Cell_R_inne1 = ( - X [
450ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm37_Cell_R_inne1 = ( - X [
452ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm38_Cell_R_inne1 = ( - X [
453ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm42_Cell_R_inne1 = ( - X [
455ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm43_Cell_R_inne1 = ( - X [
456ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm5_Cell_R_inner1 = ( - X [
457ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm_Cell_R_inner_1 = ( - X [
475ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm1_Cell_R_inner1 = ( - X [
478ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm10_Cell_R_inne1 = ( - X [
481ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm11_Cell_R_inne1 = ( - X [
484ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm12_Cell_R_inne1 = ( - X [
487ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm13_Cell_R_inne1 = ( - X [
489ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm16_Cell_R_inne1 = ( - X [
491ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm17_Cell_R_inne1 = ( - X [
493ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm20_Cell_R_inne1 = ( - X [
495ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm21_Cell_R_inne1 = ( - X [
496ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm24_Cell_R_inne1 = ( - X [
499ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm25_Cell_R_inne1 = ( - X [
502ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm26_Cell_R_inne1 = ( - X [
505ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm27_Cell_R_inne1 = ( - X [
508ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm28_Cell_R_inne1 = ( - X [
511ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm29_Cell_R_inne1 = ( - X [
513ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm32_Cell_R_inne1 = ( - X [
515ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm33_Cell_R_inne1 = ( - X [
517ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm37_Cell_R_inne1 = ( - X [
519ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm38_Cell_R_inne1 = ( - X [
520ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm4_Cell_R_inner1 = ( - X [
522ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm42_Cell_R_inne1 = ( - X [
523ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm43_Cell_R_inne1 = ( - X [
524ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm5_Cell_R_inner1 = ( - X [
525ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm_Cell_R_inner_1 = ( - X [
531ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm1_Cell_R_inner1 = ( - X [
534ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm10_Cell_R_inne1 = ( - X [
537ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm11_Cell_R_inne1 = ( - X [
540ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm12_Cell_R_inne1 = ( - X [
543ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm13_Cell_R_inne1 = ( - X [
545ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm16_Cell_R_inne1 = ( - X [
547ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm17_Cell_R_inne1 = ( - X [
549ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm20_Cell_R_inne1 = ( - X [
551ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm21_Cell_R_inne1 = ( - X [
552ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm24_Cell_R_inne1 = ( - X [
555ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm25_Cell_R_inne1 = ( - X [
559ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm26_Cell_R_inne1 = ( - X [
562ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm27_Cell_R_inne1 = ( - X [
566ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm28_Cell_R_inne1 = ( - X [
569ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm29_Cell_R_inne1 = ( - X [
572ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm32_Cell_R_inne1 = ( - X [
575ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm33_Cell_R_inne1 = ( - X [
578ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm37_Cell_R_inne1 = ( - X [
581ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm38_Cell_R_inne1 = ( - X [
583ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm4_Cell_R_inner1 = ( - X [
584ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm42_Cell_R_inne1 = ( - X [
587ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm43_Cell_R_inne1 = ( - X [
589ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm5_Cell_R_inner1 = ( - X [
592ULL ] + X [ 259ULL ] ) + X [ 260ULL ] ;
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i = - X [ 259ULL ] + - X [
260ULL ] ; if ( M [ 0ULL ] != 0 ) {
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i = - X [ 261ULL ] -
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i * 0.01 ; } else {
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i = - X [ 261ULL ] -
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i / 1.0E-6 ; } t1 [ 0ULL ]
= U [ 0ULL ] * t2 * t2 * 0.001 ; t1 [ 1ULL ] = U [ 2ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm1_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm1_Cell_R_inner_1 * 0.001 ; t1
[ 2ULL ] = U [ 4ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm10_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm10_Cell_R_inner1 * 0.001 ; t1
[ 3ULL ] = U [ 6ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm11_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm11_Cell_R_inner1 * 0.001 ; t1
[ 4ULL ] = U [ 8ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm12_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm12_Cell_R_inner1 * 0.001 ; t1
[ 5ULL ] = U [ 10ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm13_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm13_Cell_R_inner1 * 0.001 ; t1
[ 6ULL ] = U [ 12ULL ] * X [ 275ULL ] * X [ 275ULL ] * 0.001 ; t1 [ 7ULL ] =
U [ 14ULL ] * X [ 277ULL ] * X [ 277ULL ] * 0.001 ; t1 [ 8ULL ] = U [ 16ULL ]
* BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm16_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm16_Cell_R_inner1 * 0.001 ; t1
[ 9ULL ] = U [ 18ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm17_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm17_Cell_R_inner1 * 0.001 ; t1
[ 10ULL ] = U [ 20ULL ] * X [ 281ULL ] * X [ 281ULL ] * 0.001 ; t1 [ 11ULL ]
= U [ 22ULL ] * X [ 283ULL ] * X [ 283ULL ] * 0.001 ; t1 [ 12ULL ] = U [
24ULL ] * X [ 258ULL ] * X [ 258ULL ] * 0.001 ; t1 [ 13ULL ] = - ( -
53.774882324539405 + - ( U [ 26ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm20_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm20_Cell_R_inner1 * 0.001 ) ) ;
t1 [ 14ULL ] = - ( - 53.774882324539405 + - ( U [ 28ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm21_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm21_Cell_R_inner1 * 0.001 ) ) ;
t1 [ 15ULL ] = U [ 30ULL ] * X [ 288ULL ] * X [ 288ULL ] * 0.001 ; t1 [ 16ULL
] = U [ 32ULL ] * X [ 289ULL ] * X [ 289ULL ] * 0.001 ; t1 [ 17ULL ] = U [
34ULL ] * BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm24_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm24_Cell_R_inner1 * 0.001 ; t1
[ 18ULL ] = U [ 36ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm25_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm25_Cell_R_inner1 * 0.001 ; t1
[ 19ULL ] = U [ 38ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm26_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm26_Cell_R_inner1 * 0.001 ; t1
[ 20ULL ] = U [ 40ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm27_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm27_Cell_R_inner1 * 0.001 ; t1
[ 21ULL ] = U [ 42ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm28_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm28_Cell_R_inner1 * 0.001 ; t1
[ 22ULL ] = U [ 44ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm29_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm29_Cell_R_inner1 * 0.001 ; t1
[ 23ULL ] = U [ 46ULL ] * X [ 264ULL ] * X [ 264ULL ] * 0.001 ; t1 [ 24ULL ]
= U [ 48ULL ] * X [ 305ULL ] * X [ 305ULL ] * 0.001 ; t1 [ 25ULL ] = U [
50ULL ] * X [ 307ULL ] * X [ 307ULL ] * 0.001 ; t1 [ 26ULL ] = U [ 52ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm32_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm32_Cell_R_inner1 * 0.001 ; t1
[ 27ULL ] = U [ 54ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm33_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm33_Cell_R_inner1 * 0.001 ; t1
[ 28ULL ] = U [ 56ULL ] * X [ 309ULL ] * X [ 309ULL ] * 0.001 ; t1 [ 29ULL ]
= U [ 58ULL ] * X [ 311ULL ] * X [ 311ULL ] * 0.001 ; t1 [ 30ULL ] = U [
60ULL ] * X [ 293ULL ] * X [ 293ULL ] * 0.001 ; t1 [ 31ULL ] = - ( -
53.774882324539405 + - ( U [ 62ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm37_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm37_Cell_R_inner1 * 0.001 ) ) ;
t1 [ 32ULL ] = - ( - 53.774882324539405 + - ( U [ 64ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm38_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm38_Cell_R_inner1 * 0.001 ) ) ;
t1 [ 33ULL ] = U [ 66ULL ] * X [ 313ULL ] * X [ 313ULL ] * 0.001 ; t1 [ 34ULL
] = U [ 68ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm4_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm4_Cell_R_inner_1 * 0.001 ; t1
[ 35ULL ] = U [ 70ULL ] * X [ 314ULL ] * X [ 314ULL ] * 0.001 ; t1 [ 36ULL ]
= U [ 72ULL ] * X [ 296ULL ] * X [ 296ULL ] * 0.001 ; t1 [ 37ULL ] = U [
74ULL ] * BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm42_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm42_Cell_R_inner1 * 0.001 ; t1
[ 38ULL ] = U [ 76ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm43_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm43_Cell_R_inner1 * 0.001 ; t1
[ 39ULL ] = U [ 78ULL ] * X [ 318ULL ] * X [ 318ULL ] * 0.001 ; t1 [ 40ULL ]
= U [ 80ULL ] * X [ 319ULL ] * X [ 319ULL ] * 0.001 ; t1 [ 41ULL ] = U [
82ULL ] * X [ 299ULL ] * X [ 299ULL ] * 0.001 ; t1 [ 42ULL ] = U [ 84ULL ] *
X [ 302ULL ] * X [ 302ULL ] * 0.001 ; t1 [ 43ULL ] = U [ 86ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm5_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm5_Cell_R_inner_1 * 0.001 ; t1
[ 44ULL ] = U [ 88ULL ] * X [ 317ULL ] * X [ 317ULL ] * 0.001 ; t1 [ 45ULL ]
= U [ 90ULL ] * X [ 320ULL ] * X [ 320ULL ] * 0.001 ; t1 [ 46ULL ] = U [
92ULL ] * X [ 268ULL ] * X [ 268ULL ] * 0.001 ; t1 [ 47ULL ] = U [ 94ULL ] *
X [ 271ULL ] * X [ 271ULL ] * 0.001 ; t1 [ 48ULL ] = U [ 96ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm_Cell_R_inner_1 * 0.001 ; t1
[ 49ULL ] = U [ 98ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm1_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm1_Cell_R_inner1 * 0.001 ; t1
[ 50ULL ] = U [ 100ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm10_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm10_Cell_R_inne1 * 0.001 ; t1
[ 51ULL ] = U [ 102ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm11_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm11_Cell_R_inne1 * 0.001 ; t1
[ 52ULL ] = U [ 104ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm12_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm12_Cell_R_inne1 * 0.001 ; t1
[ 53ULL ] = U [ 106ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm13_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm13_Cell_R_inne1 * 0.001 ; t1
[ 54ULL ] = U [ 108ULL ] * X [ 352ULL ] * X [ 352ULL ] * 0.001 ; t1 [ 55ULL ]
= U [ 110ULL ] * X [ 354ULL ] * X [ 354ULL ] * 0.001 ; t1 [ 56ULL ] = U [
112ULL ] * BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm16_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm16_Cell_R_inne1 * 0.001 ; t1
[ 57ULL ] = U [ 114ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm17_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm17_Cell_R_inne1 * 0.001 ; t1
[ 58ULL ] = U [ 116ULL ] * X [ 356ULL ] * X [ 356ULL ] * 0.001 ; t1 [ 59ULL ]
= U [ 118ULL ] * X [ 358ULL ] * X [ 358ULL ] * 0.001 ; t1 [ 60ULL ] = U [
120ULL ] * X [ 340ULL ] * X [ 340ULL ] * 0.001 ; t1 [ 61ULL ] = - ( -
53.774882324539405 + - ( U [ 122ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm20_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm20_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 62ULL ] = - ( - 53.774882324539405 + - ( U [ 124ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm21_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm21_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 63ULL ] = U [ 126ULL ] * X [ 360ULL ] * X [ 360ULL ] * 0.001 ; t1 [
64ULL ] = U [ 128ULL ] * X [ 361ULL ] * X [ 361ULL ] * 0.001 ; t1 [ 65ULL ] =
U [ 130ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm24_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm24_Cell_R_inne1 * 0.001 ; t1
[ 66ULL ] = U [ 132ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm25_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm25_Cell_R_inne1 * 0.001 ; t1
[ 67ULL ] = U [ 134ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm26_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm26_Cell_R_inne1 * 0.001 ; t1
[ 68ULL ] = U [ 136ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm27_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm27_Cell_R_inne1 * 0.001 ; t1
[ 69ULL ] = U [ 138ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm28_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm28_Cell_R_inne1 * 0.001 ; t1
[ 70ULL ] = U [ 140ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm29_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm29_Cell_R_inne1 * 0.001 ; t1
[ 71ULL ] = U [ 142ULL ] * X [ 343ULL ] * X [ 343ULL ] * 0.001 ; t1 [ 72ULL ]
= U [ 144ULL ] * X [ 376ULL ] * X [ 376ULL ] * 0.001 ; t1 [ 73ULL ] = U [
146ULL ] * X [ 378ULL ] * X [ 378ULL ] * 0.001 ; t1 [ 74ULL ] = U [ 148ULL ]
* BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm32_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm32_Cell_R_inne1 * 0.001 ; t1
[ 75ULL ] = U [ 150ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm33_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm33_Cell_R_inne1 * 0.001 ; t1
[ 76ULL ] = U [ 152ULL ] * X [ 380ULL ] * X [ 380ULL ] * 0.001 ; t1 [ 77ULL ]
= U [ 154ULL ] * X [ 382ULL ] * X [ 382ULL ] * 0.001 ; t1 [ 78ULL ] = U [
156ULL ] * X [ 364ULL ] * X [ 364ULL ] * 0.001 ; t1 [ 79ULL ] = - ( -
53.774882324539405 + - ( U [ 158ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm37_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm37_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 80ULL ] = - ( - 53.774882324539405 + - ( U [ 160ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm38_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm38_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 81ULL ] = U [ 162ULL ] * X [ 384ULL ] * X [ 384ULL ] * 0.001 ; t1 [
82ULL ] = U [ 164ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm4_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm4_Cell_R_inner1 * 0.001 ; t1
[ 83ULL ] = U [ 166ULL ] * X [ 385ULL ] * X [ 385ULL ] * 0.001 ; t1 [ 84ULL ]
= U [ 168ULL ] * X [ 367ULL ] * X [ 367ULL ] * 0.001 ; t1 [ 85ULL ] = U [
170ULL ] * BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm42_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm42_Cell_R_inne1 * 0.001 ; t1
[ 86ULL ] = U [ 172ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm43_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm43_Cell_R_inne1 * 0.001 ; t1
[ 87ULL ] = U [ 174ULL ] * X [ 388ULL ] * X [ 388ULL ] * 0.001 ; t1 [ 88ULL ]
= U [ 176ULL ] * X [ 389ULL ] * X [ 389ULL ] * 0.001 ; t1 [ 89ULL ] = U [
178ULL ] * X [ 370ULL ] * X [ 370ULL ] * 0.001 ; t1 [ 90ULL ] = U [ 180ULL ]
* X [ 373ULL ] * X [ 373ULL ] * 0.001 ; t1 [ 91ULL ] = U [ 182ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm5_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm5_Cell_R_inner1 * 0.001 ; t1
[ 92ULL ] = U [ 184ULL ] * X [ 387ULL ] * X [ 387ULL ] * 0.001 ; t1 [ 93ULL ]
= U [ 186ULL ] * X [ 390ULL ] * X [ 390ULL ] * 0.001 ; t1 [ 94ULL ] = U [
188ULL ] * X [ 346ULL ] * X [ 346ULL ] * 0.001 ; t1 [ 95ULL ] = U [ 190ULL ]
* X [ 349ULL ] * X [ 349ULL ] * 0.001 ; t1 [ 96ULL ] = U [ 192ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm_Cell_R_inner_1 * 0.001 ; t1
[ 97ULL ] = U [ 194ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm1_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm1_Cell_R_inner1 * 0.001 ; t1
[ 98ULL ] = U [ 196ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm10_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm10_Cell_R_inne1 * 0.001 ; t1
[ 99ULL ] = U [ 198ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm11_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm11_Cell_R_inne1 * 0.001 ; t1
[ 100ULL ] = U [ 200ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm12_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm12_Cell_R_inne1 * 0.001 ; t1
[ 101ULL ] = U [ 202ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm13_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm13_Cell_R_inne1 * 0.001 ; t1
[ 102ULL ] = U [ 204ULL ] * X [ 420ULL ] * X [ 420ULL ] * 0.001 ; t1 [ 103ULL
] = U [ 206ULL ] * X [ 422ULL ] * X [ 422ULL ] * 0.001 ; t1 [ 104ULL ] = U [
208ULL ] * BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm16_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm16_Cell_R_inne1 * 0.001 ; t1
[ 105ULL ] = U [ 210ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm17_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm17_Cell_R_inne1 * 0.001 ; t1
[ 106ULL ] = U [ 212ULL ] * X [ 424ULL ] * X [ 424ULL ] * 0.001 ; t1 [ 107ULL
] = U [ 214ULL ] * X [ 426ULL ] * X [ 426ULL ] * 0.001 ; t1 [ 108ULL ] = U [
216ULL ] * X [ 408ULL ] * X [ 408ULL ] * 0.001 ; t1 [ 109ULL ] = - ( -
53.774882324539405 + - ( U [ 218ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm20_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm20_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 110ULL ] = - ( - 53.774882324539405 + - ( U [ 220ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm21_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm21_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 111ULL ] = U [ 222ULL ] * X [ 428ULL ] * X [ 428ULL ] * 0.001 ; t1 [
112ULL ] = U [ 224ULL ] * X [ 429ULL ] * X [ 429ULL ] * 0.001 ; t1 [ 113ULL ]
= U [ 226ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm24_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm24_Cell_R_inne1 * 0.001 ; t1
[ 114ULL ] = U [ 228ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm25_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm25_Cell_R_inne1 * 0.001 ; t1
[ 115ULL ] = U [ 230ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm26_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm26_Cell_R_inne1 * 0.001 ; t1
[ 116ULL ] = U [ 232ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm27_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm27_Cell_R_inne1 * 0.001 ; t1
[ 117ULL ] = U [ 234ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm28_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm28_Cell_R_inne1 * 0.001 ; t1
[ 118ULL ] = U [ 236ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm29_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm29_Cell_R_inne1 * 0.001 ; t1
[ 119ULL ] = U [ 238ULL ] * X [ 411ULL ] * X [ 411ULL ] * 0.001 ; t1 [ 120ULL
] = U [ 240ULL ] * X [ 444ULL ] * X [ 444ULL ] * 0.001 ; t1 [ 121ULL ] = U [
242ULL ] * X [ 446ULL ] * X [ 446ULL ] * 0.001 ; t1 [ 122ULL ] = U [ 244ULL ]
* BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm32_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm32_Cell_R_inne1 * 0.001 ; t1
[ 123ULL ] = U [ 246ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm33_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm33_Cell_R_inne1 * 0.001 ; t1
[ 124ULL ] = U [ 248ULL ] * X [ 448ULL ] * X [ 448ULL ] * 0.001 ; t1 [ 125ULL
] = U [ 250ULL ] * X [ 450ULL ] * X [ 450ULL ] * 0.001 ; t1 [ 126ULL ] = U [
252ULL ] * X [ 432ULL ] * X [ 432ULL ] * 0.001 ; t1 [ 127ULL ] = - ( -
53.774882324539405 + - ( U [ 254ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm37_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm37_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 128ULL ] = - ( - 53.774882324539405 + - ( U [ 256ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm38_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm38_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 129ULL ] = U [ 258ULL ] * X [ 452ULL ] * X [ 452ULL ] * 0.001 ; t1 [
130ULL ] = U [ 260ULL ] * X [ 259ULL ] * X [ 259ULL ] * 0.001 ; t1 [ 131ULL ]
= U [ 262ULL ] * X [ 453ULL ] * X [ 453ULL ] * 0.001 ; t1 [ 132ULL ] = U [
264ULL ] * X [ 435ULL ] * X [ 435ULL ] * 0.001 ; t1 [ 133ULL ] = U [ 266ULL ]
* BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm42_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm42_Cell_R_inne1 * 0.001 ; t1
[ 134ULL ] = U [ 268ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm43_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm43_Cell_R_inne1 * 0.001 ; t1
[ 135ULL ] = U [ 270ULL ] * X [ 455ULL ] * X [ 455ULL ] * 0.001 ; t1 [ 136ULL
] = U [ 272ULL ] * X [ 456ULL ] * X [ 456ULL ] * 0.001 ; t1 [ 137ULL ] = U [
274ULL ] * X [ 438ULL ] * X [ 438ULL ] * 0.001 ; t1 [ 138ULL ] = U [ 276ULL ]
* X [ 441ULL ] * X [ 441ULL ] * 0.001 ; t1 [ 139ULL ] = U [ 278ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm5_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm5_Cell_R_inner1 * 0.001 ; t1
[ 140ULL ] = U [ 280ULL ] * X [ 260ULL ] * X [ 260ULL ] * 0.001 ; t1 [ 141ULL
] = U [ 282ULL ] * X [ 457ULL ] * X [ 457ULL ] * 0.001 ; t1 [ 142ULL ] = U [
284ULL ] * X [ 414ULL ] * X [ 414ULL ] * 0.001 ; t1 [ 143ULL ] = U [ 286ULL ]
* X [ 417ULL ] * X [ 417ULL ] * 0.001 ; t1 [ 144ULL ] = U [ 288ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm_Cell_R_inner_1 * 0.001 ; t1
[ 145ULL ] = U [ 290ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm1_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm1_Cell_R_inner1 * 0.001 ; t1
[ 146ULL ] = U [ 292ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm10_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm10_Cell_R_inne1 * 0.001 ; t1
[ 147ULL ] = U [ 294ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm11_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm11_Cell_R_inne1 * 0.001 ; t1
[ 148ULL ] = U [ 296ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm12_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm12_Cell_R_inne1 * 0.001 ; t1
[ 149ULL ] = U [ 298ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm13_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm13_Cell_R_inne1 * 0.001 ; t1
[ 150ULL ] = U [ 300ULL ] * X [ 487ULL ] * X [ 487ULL ] * 0.001 ; t1 [ 151ULL
] = U [ 302ULL ] * X [ 489ULL ] * X [ 489ULL ] * 0.001 ; t1 [ 152ULL ] = U [
304ULL ] * BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm16_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm16_Cell_R_inne1 * 0.001 ; t1
[ 153ULL ] = U [ 306ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm17_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm17_Cell_R_inne1 * 0.001 ; t1
[ 154ULL ] = U [ 308ULL ] * X [ 491ULL ] * X [ 491ULL ] * 0.001 ; t1 [ 155ULL
] = U [ 310ULL ] * X [ 493ULL ] * X [ 493ULL ] * 0.001 ; t1 [ 156ULL ] = U [
312ULL ] * X [ 475ULL ] * X [ 475ULL ] * 0.001 ; t1 [ 157ULL ] = - ( -
53.774882324539405 + - ( U [ 314ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm20_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm20_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 158ULL ] = - ( - 53.774882324539405 + - ( U [ 316ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm21_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm21_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 159ULL ] = U [ 318ULL ] * X [ 495ULL ] * X [ 495ULL ] * 0.001 ; t1 [
160ULL ] = U [ 320ULL ] * X [ 496ULL ] * X [ 496ULL ] * 0.001 ; t1 [ 161ULL ]
= U [ 322ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm24_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm24_Cell_R_inne1 * 0.001 ; t1
[ 162ULL ] = U [ 324ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm25_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm25_Cell_R_inne1 * 0.001 ; t1
[ 163ULL ] = U [ 326ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm26_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm26_Cell_R_inne1 * 0.001 ; t1
[ 164ULL ] = U [ 328ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm27_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm27_Cell_R_inne1 * 0.001 ; t1
[ 165ULL ] = U [ 330ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm28_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm28_Cell_R_inne1 * 0.001 ; t1
[ 166ULL ] = U [ 332ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm29_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm29_Cell_R_inne1 * 0.001 ; t1
[ 167ULL ] = U [ 334ULL ] * X [ 478ULL ] * X [ 478ULL ] * 0.001 ; t1 [ 168ULL
] = U [ 336ULL ] * X [ 511ULL ] * X [ 511ULL ] * 0.001 ; t1 [ 169ULL ] = U [
338ULL ] * X [ 513ULL ] * X [ 513ULL ] * 0.001 ; t1 [ 170ULL ] = U [ 340ULL ]
* BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm32_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm32_Cell_R_inne1 * 0.001 ; t1
[ 171ULL ] = U [ 342ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm33_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm33_Cell_R_inne1 * 0.001 ; t1
[ 172ULL ] = U [ 344ULL ] * X [ 515ULL ] * X [ 515ULL ] * 0.001 ; t1 [ 173ULL
] = U [ 346ULL ] * X [ 517ULL ] * X [ 517ULL ] * 0.001 ; t1 [ 174ULL ] = U [
348ULL ] * X [ 499ULL ] * X [ 499ULL ] * 0.001 ; t1 [ 175ULL ] = - ( -
53.774882324539405 + - ( U [ 350ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm37_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm37_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 176ULL ] = - ( - 53.774882324539405 + - ( U [ 352ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm38_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm38_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 177ULL ] = U [ 354ULL ] * X [ 519ULL ] * X [ 519ULL ] * 0.001 ; t1 [
178ULL ] = U [ 356ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm4_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm4_Cell_R_inner1 * 0.001 ; t1
[ 179ULL ] = U [ 358ULL ] * X [ 520ULL ] * X [ 520ULL ] * 0.001 ; t1 [ 180ULL
] = U [ 360ULL ] * X [ 502ULL ] * X [ 502ULL ] * 0.001 ; t1 [ 181ULL ] = U [
362ULL ] * BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm42_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm42_Cell_R_inne1 * 0.001 ; t1
[ 182ULL ] = U [ 364ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm43_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm43_Cell_R_inne1 * 0.001 ; t1
[ 183ULL ] = U [ 366ULL ] * X [ 523ULL ] * X [ 523ULL ] * 0.001 ; t1 [ 184ULL
] = U [ 368ULL ] * X [ 524ULL ] * X [ 524ULL ] * 0.001 ; t1 [ 185ULL ] = U [
370ULL ] * X [ 505ULL ] * X [ 505ULL ] * 0.001 ; t1 [ 186ULL ] = U [ 372ULL ]
* X [ 508ULL ] * X [ 508ULL ] * 0.001 ; t1 [ 187ULL ] = U [ 374ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm5_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm5_Cell_R_inner1 * 0.001 ; t1
[ 188ULL ] = U [ 376ULL ] * X [ 522ULL ] * X [ 522ULL ] * 0.001 ; t1 [ 189ULL
] = U [ 378ULL ] * X [ 525ULL ] * X [ 525ULL ] * 0.001 ; t1 [ 190ULL ] = U [
380ULL ] * X [ 481ULL ] * X [ 481ULL ] * 0.001 ; t1 [ 191ULL ] = U [ 382ULL ]
* X [ 484ULL ] * X [ 484ULL ] * 0.001 ; t1 [ 192ULL ] = U [ 384ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm_Cell_R_inner_1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm_Cell_R_inner_1 * 0.001 ; t1
[ 193ULL ] = U [ 386ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm1_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm1_Cell_R_inner1 * 0.001 ; t1
[ 194ULL ] = U [ 388ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm10_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm10_Cell_R_inne1 * 0.001 ; t1
[ 195ULL ] = U [ 390ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm11_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm11_Cell_R_inne1 * 0.001 ; t1
[ 196ULL ] = U [ 392ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm12_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm12_Cell_R_inne1 * 0.001 ; t1
[ 197ULL ] = U [ 394ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm13_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm13_Cell_R_inne1 * 0.001 ; t1
[ 198ULL ] = U [ 396ULL ] * X [ 543ULL ] * X [ 543ULL ] * 0.001 ; t1 [ 199ULL
] = U [ 398ULL ] * X [ 545ULL ] * X [ 545ULL ] * 0.001 ; t1 [ 200ULL ] = U [
400ULL ] * BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm16_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm16_Cell_R_inne1 * 0.001 ; t1
[ 201ULL ] = U [ 402ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm17_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm17_Cell_R_inne1 * 0.001 ; t1
[ 202ULL ] = U [ 404ULL ] * X [ 547ULL ] * X [ 547ULL ] * 0.001 ; t1 [ 203ULL
] = U [ 406ULL ] * X [ 549ULL ] * X [ 549ULL ] * 0.001 ; t1 [ 204ULL ] = U [
408ULL ] * X [ 531ULL ] * X [ 531ULL ] * 0.001 ; t1 [ 205ULL ] = - ( -
53.774882324539405 + - ( U [ 410ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm20_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm20_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 206ULL ] = - ( - 53.774882324539405 + - ( U [ 412ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm21_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm21_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 207ULL ] = U [ 414ULL ] * X [ 551ULL ] * X [ 551ULL ] * 0.001 ; t1 [
208ULL ] = U [ 416ULL ] * X [ 552ULL ] * X [ 552ULL ] * 0.001 ; t1 [ 209ULL ]
= U [ 418ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm24_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm24_Cell_R_inne1 * 0.001 ; t1
[ 210ULL ] = U [ 420ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm25_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm25_Cell_R_inne1 * 0.001 ; t1
[ 211ULL ] = U [ 422ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm26_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm26_Cell_R_inne1 * 0.001 ; t1
[ 212ULL ] = U [ 424ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm27_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm27_Cell_R_inne1 * 0.001 ; t1
[ 213ULL ] = U [ 426ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm28_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm28_Cell_R_inne1 * 0.001 ; t1
[ 214ULL ] = U [ 428ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm29_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm29_Cell_R_inne1 * 0.001 ; t1
[ 215ULL ] = U [ 430ULL ] * X [ 534ULL ] * X [ 534ULL ] * 0.001 ; t1 [ 216ULL
] = U [ 432ULL ] * X [ 569ULL ] * X [ 569ULL ] * 0.001 ; t1 [ 217ULL ] = U [
434ULL ] * X [ 572ULL ] * X [ 572ULL ] * 0.001 ; t1 [ 218ULL ] = U [ 436ULL ]
* BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm32_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm32_Cell_R_inne1 * 0.001 ; t1
[ 219ULL ] = U [ 438ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm33_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm33_Cell_R_inne1 * 0.001 ; t1
[ 220ULL ] = U [ 440ULL ] * X [ 575ULL ] * X [ 575ULL ] * 0.001 ; t1 [ 221ULL
] = U [ 442ULL ] * X [ 578ULL ] * X [ 578ULL ] * 0.001 ; t1 [ 222ULL ] = U [
444ULL ] * X [ 555ULL ] * X [ 555ULL ] * 0.001 ; t1 [ 223ULL ] = - ( -
53.774882324539405 + - ( U [ 446ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm37_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm37_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 224ULL ] = - ( - 53.774882324539405 + - ( U [ 448ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm38_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm38_Cell_R_inne1 * 0.001 ) ) ;
t1 [ 225ULL ] = U [ 450ULL ] * X [ 581ULL ] * X [ 581ULL ] * 0.001 ; t1 [
226ULL ] = U [ 452ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm4_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm4_Cell_R_inner1 * 0.001 ; t1
[ 227ULL ] = U [ 454ULL ] * X [ 583ULL ] * X [ 583ULL ] * 0.001 ; t1 [ 228ULL
] = U [ 456ULL ] * X [ 559ULL ] * X [ 559ULL ] * 0.001 ; t1 [ 229ULL ] = U [
458ULL ] * BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm42_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm42_Cell_R_inne1 * 0.001 ; t1
[ 230ULL ] = U [ 460ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm43_Cell_R_inne1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm43_Cell_R_inne1 * 0.001 ; t1
[ 231ULL ] = U [ 462ULL ] * X [ 587ULL ] * X [ 587ULL ] * 0.001 ; t1 [ 232ULL
] = U [ 464ULL ] * X [ 589ULL ] * X [ 589ULL ] * 0.001 ; t1 [ 233ULL ] = U [
466ULL ] * X [ 562ULL ] * X [ 562ULL ] * 0.001 ; t1 [ 234ULL ] = U [ 468ULL ]
* X [ 566ULL ] * X [ 566ULL ] * 0.001 ; t1 [ 235ULL ] = U [ 470ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm5_Cell_R_inner1 *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm5_Cell_R_inner1 * 0.001 ; t1
[ 236ULL ] = U [ 472ULL ] * X [ 584ULL ] * X [ 584ULL ] * 0.001 ; t1 [ 237ULL
] = U [ 474ULL ] * X [ 592ULL ] * X [ 592ULL ] * 0.001 ; t1 [ 238ULL ] = U [
476ULL ] * X [ 537ULL ] * X [ 537ULL ] * 0.001 ; t1 [ 239ULL ] = U [ 478ULL ]
* X [ 540ULL ] * X [ 540ULL ] * 0.001 ; t1 [ 240ULL ] = U [ 0ULL ] * t2 ; t1
[ 241ULL ] = U [ 2ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm1_Cell_R_inner_1 ; t1 [ 242ULL
] = U [ 4ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm10_Cell_R_inner1 ; t1 [ 243ULL
] = U [ 6ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm11_Cell_R_inner1 ; t1 [ 244ULL
] = U [ 8ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm12_Cell_R_inner1 ; t1 [ 245ULL
] = U [ 10ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm13_Cell_R_inner1 ; t1 [ 246ULL
] = U [ 12ULL ] * X [ 275ULL ] ; t1 [ 247ULL ] = U [ 14ULL ] * X [ 277ULL ] ;
t1 [ 248ULL ] = U [ 16ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm16_Cell_R_inner1 ; t1 [ 249ULL
] = U [ 18ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm17_Cell_R_inner1 ; t1 [ 250ULL
] = U [ 20ULL ] * X [ 281ULL ] ; t1 [ 251ULL ] = U [ 22ULL ] * X [ 283ULL ] ;
t1 [ 252ULL ] = U [ 24ULL ] * X [ 258ULL ] ; t1 [ 253ULL ] = U [ 26ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm20_Cell_R_inner1 ; t2 = -
3.3609301452837124E+7 ; t1 [ 254ULL ] = t2 / 625000.0 ; t1 [ 255ULL ] = U [
28ULL ] * BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm21_Cell_R_inner1 ;
t1 [ 256ULL ] = t2 / 625000.0 ; t1 [ 257ULL ] = U [ 30ULL ] * X [ 288ULL ] ;
t1 [ 258ULL ] = U [ 32ULL ] * X [ 289ULL ] ; t1 [ 259ULL ] = U [ 34ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm24_Cell_R_inner1 ; t1 [ 260ULL
] = U [ 36ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm25_Cell_R_inner1 ; t1 [ 261ULL
] = 0.0 ; t1 [ 262ULL ] = U [ 38ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm26_Cell_R_inner1 ; t1 [ 263ULL
] = U [ 40ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm27_Cell_R_inner1 ; t1 [ 264ULL
] = 0.0 ; t1 [ 265ULL ] = U [ 42ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm28_Cell_R_inner1 ; t1 [ 266ULL
] = U [ 44ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm29_Cell_R_inner1 ; t1 [ 267ULL
] = 0.0 ; t1 [ 268ULL ] = U [ 46ULL ] * X [ 264ULL ] ; t1 [ 269ULL ] = U [
48ULL ] * X [ 305ULL ] ; t1 [ 270ULL ] = U [ 50ULL ] * X [ 307ULL ] ; t1 [
271ULL ] = 0.0 ; t1 [ 272ULL ] = U [ 52ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm32_Cell_R_inner1 ; t1 [ 273ULL
] = U [ 54ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm33_Cell_R_inner1 ; t1 [ 274ULL
] = 0.0 ; t1 [ 275ULL ] = U [ 56ULL ] * X [ 309ULL ] ; t1 [ 276ULL ] = U [
58ULL ] * X [ 311ULL ] ; t1 [ 277ULL ] = 0.0 ; t1 [ 278ULL ] = U [ 60ULL ] *
X [ 293ULL ] ; t1 [ 279ULL ] = U [ 62ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm37_Cell_R_inner1 ; t1 [ 280ULL
] = t2 / 625000.0 ; t1 [ 281ULL ] = U [ 64ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm38_Cell_R_inner1 ; t1 [ 282ULL
] = 0.0 ; t1 [ 283ULL ] = t2 / 625000.0 ; t1 [ 284ULL ] = U [ 66ULL ] * X [
313ULL ] ; t1 [ 285ULL ] = U [ 68ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm4_Cell_R_inner_1 ; t1 [ 286ULL
] = U [ 70ULL ] * X [ 314ULL ] ; t1 [ 287ULL ] = 0.0 ; t1 [ 288ULL ] = U [
72ULL ] * X [ 296ULL ] ; t1 [ 289ULL ] = 0.0 ; t1 [ 290ULL ] = U [ 74ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm42_Cell_R_inner1 ; t1 [ 291ULL
] = U [ 76ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm43_Cell_R_inner1 ; t1 [ 292ULL
] = 0.0 ; t1 [ 293ULL ] = U [ 78ULL ] * X [ 318ULL ] ; t1 [ 294ULL ] = U [
80ULL ] * X [ 319ULL ] ; t1 [ 295ULL ] = 0.0 ; t1 [ 296ULL ] = U [ 82ULL ] *
X [ 299ULL ] ; t1 [ 297ULL ] = U [ 84ULL ] * X [ 302ULL ] ; t1 [ 298ULL ] =
0.0 ; t1 [ 299ULL ] = U [ 86ULL ] *
BATTERIE_120S2P_73kWh_Subsystem_Cell_elec_therm5_Cell_R_inner_1 ; t1 [ 300ULL
] = U [ 88ULL ] * X [ 317ULL ] ; t1 [ 301ULL ] = U [ 90ULL ] * X [ 320ULL ] ;
t1 [ 302ULL ] = U [ 92ULL ] * X [ 268ULL ] ; t1 [ 303ULL ] = U [ 94ULL ] * X
[ 271ULL ] ; t1 [ 304ULL ] = - 8.5878186968786974 ; t1 [ 305ULL ] = -
8.5878186968786974 ; t1 [ 306ULL ] = - 8.5878186968786974 ; t1 [ 307ULL ] = -
8.5878186968786974 ; t1 [ 308ULL ] = 303.15 ; t1 [ 309ULL ] = 303.15 ; t1 [
310ULL ] = 303.15 ; t1 [ 311ULL ] = 303.15 ; t1 [ 312ULL ] = 303.15 ; t1 [
313ULL ] = 303.15 ; t1 [ 314ULL ] = 303.15 ; t1 [ 315ULL ] = 303.15 ; t1 [
316ULL ] = 303.15 ; t1 [ 317ULL ] = 303.15 ; t1 [ 318ULL ] = 303.15 ; t1 [
319ULL ] = 303.15 ; t1 [ 320ULL ] = U [ 96ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm_Cell_R_inner_1 ; t1 [ 321ULL
] = U [ 98ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm1_Cell_R_inner1 ; t1 [ 322ULL
] = U [ 100ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm10_Cell_R_inne1 ; t1 [ 323ULL
] = U [ 102ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm11_Cell_R_inne1 ; t1 [ 324ULL
] = U [ 104ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm12_Cell_R_inne1 ; t1 [ 325ULL
] = U [ 106ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm13_Cell_R_inne1 ; t1 [ 326ULL
] = U [ 108ULL ] * X [ 352ULL ] ; t1 [ 327ULL ] = U [ 110ULL ] * X [ 354ULL ]
; t1 [ 328ULL ] = U [ 112ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm16_Cell_R_inne1 ; t1 [ 329ULL
] = U [ 114ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm17_Cell_R_inne1 ; t1 [ 330ULL
] = U [ 116ULL ] * X [ 356ULL ] ; t1 [ 331ULL ] = U [ 118ULL ] * X [ 358ULL ]
; t1 [ 332ULL ] = U [ 120ULL ] * X [ 340ULL ] ; t1 [ 333ULL ] = U [ 122ULL ]
* BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm20_Cell_R_inne1 ; t1 [
334ULL ] = t2 / 625000.0 ; t1 [ 335ULL ] = U [ 124ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm21_Cell_R_inne1 ; t1 [ 336ULL
] = t2 / 625000.0 ; t1 [ 337ULL ] = U [ 126ULL ] * X [ 360ULL ] ; t1 [ 338ULL
] = U [ 128ULL ] * X [ 361ULL ] ; t1 [ 339ULL ] = U [ 130ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm24_Cell_R_inne1 ; t1 [ 340ULL
] = U [ 132ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm25_Cell_R_inne1 ; t1 [ 341ULL
] = 0.0 ; t1 [ 342ULL ] = U [ 134ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm26_Cell_R_inne1 ; t1 [ 343ULL
] = U [ 136ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm27_Cell_R_inne1 ; t1 [ 344ULL
] = 0.0 ; t1 [ 345ULL ] = U [ 138ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm28_Cell_R_inne1 ; t1 [ 346ULL
] = U [ 140ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm29_Cell_R_inne1 ; t1 [ 347ULL
] = 0.0 ; t1 [ 348ULL ] = U [ 142ULL ] * X [ 343ULL ] ; t1 [ 349ULL ] = U [
144ULL ] * X [ 376ULL ] ; t1 [ 350ULL ] = U [ 146ULL ] * X [ 378ULL ] ; t1 [
351ULL ] = 0.0 ; t1 [ 352ULL ] = U [ 148ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm32_Cell_R_inne1 ; t1 [ 353ULL
] = U [ 150ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm33_Cell_R_inne1 ; t1 [ 354ULL
] = 0.0 ; t1 [ 355ULL ] = U [ 152ULL ] * X [ 380ULL ] ; t1 [ 356ULL ] = U [
154ULL ] * X [ 382ULL ] ; t1 [ 357ULL ] = 0.0 ; t1 [ 358ULL ] = U [ 156ULL ]
* X [ 364ULL ] ; t1 [ 359ULL ] = U [ 158ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm37_Cell_R_inne1 ; t1 [ 360ULL
] = t2 / 625000.0 ; t1 [ 361ULL ] = U [ 160ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm38_Cell_R_inne1 ; t1 [ 362ULL
] = 0.0 ; t1 [ 363ULL ] = t2 / 625000.0 ; t1 [ 364ULL ] = U [ 162ULL ] * X [
384ULL ] ; t1 [ 365ULL ] = U [ 164ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm4_Cell_R_inner1 ; t1 [ 366ULL
] = U [ 166ULL ] * X [ 385ULL ] ; t1 [ 367ULL ] = 0.0 ; t1 [ 368ULL ] = U [
168ULL ] * X [ 367ULL ] ; t1 [ 369ULL ] = 0.0 ; t1 [ 370ULL ] = U [ 170ULL ]
* BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm42_Cell_R_inne1 ; t1 [
371ULL ] = U [ 172ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm43_Cell_R_inne1 ; t1 [ 372ULL
] = 0.0 ; t1 [ 373ULL ] = U [ 174ULL ] * X [ 388ULL ] ; t1 [ 374ULL ] = U [
176ULL ] * X [ 389ULL ] ; t1 [ 375ULL ] = 0.0 ; t1 [ 376ULL ] = U [ 178ULL ]
* X [ 370ULL ] ; t1 [ 377ULL ] = U [ 180ULL ] * X [ 373ULL ] ; t1 [ 378ULL ]
= 0.0 ; t1 [ 379ULL ] = U [ 182ULL ] *
BATTERIE_120S2P_73kWh_Subsystem1_Cell_elec_therm5_Cell_R_inner1 ; t1 [ 380ULL
] = U [ 184ULL ] * X [ 387ULL ] ; t1 [ 381ULL ] = U [ 186ULL ] * X [ 390ULL ]
; t1 [ 382ULL ] = U [ 188ULL ] * X [ 346ULL ] ; t1 [ 383ULL ] = U [ 190ULL ]
* X [ 349ULL ] ; t1 [ 384ULL ] = - 8.5878186968786974 ; t1 [ 385ULL ] = -
8.5878186968786974 ; t1 [ 386ULL ] = - 8.5878186968786974 ; t1 [ 387ULL ] = -
8.5878186968786974 ; t1 [ 388ULL ] = U [ 192ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm_Cell_R_inner_1 ; t1 [ 389ULL
] = U [ 194ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm1_Cell_R_inner1 ; t1 [ 390ULL
] = U [ 196ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm10_Cell_R_inne1 ; t1 [ 391ULL
] = U [ 198ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm11_Cell_R_inne1 ; t1 [ 392ULL
] = U [ 200ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm12_Cell_R_inne1 ; t1 [ 393ULL
] = U [ 202ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm13_Cell_R_inne1 ; t1 [ 394ULL
] = U [ 204ULL ] * X [ 420ULL ] ; t1 [ 395ULL ] = U [ 206ULL ] * X [ 422ULL ]
; t1 [ 396ULL ] = U [ 208ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm16_Cell_R_inne1 ; t1 [ 397ULL
] = U [ 210ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm17_Cell_R_inne1 ; t1 [ 398ULL
] = U [ 212ULL ] * X [ 424ULL ] ; t1 [ 399ULL ] = U [ 214ULL ] * X [ 426ULL ]
; t1 [ 400ULL ] = U [ 216ULL ] * X [ 408ULL ] ; t1 [ 401ULL ] = U [ 218ULL ]
* BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm20_Cell_R_inne1 ; t1 [
402ULL ] = t2 / 625000.0 ; t1 [ 403ULL ] = U [ 220ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm21_Cell_R_inne1 ; t1 [ 404ULL
] = t2 / 625000.0 ; t1 [ 405ULL ] = U [ 222ULL ] * X [ 428ULL ] ; t1 [ 406ULL
] = U [ 224ULL ] * X [ 429ULL ] ; t1 [ 407ULL ] = U [ 226ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm24_Cell_R_inne1 ; t1 [ 408ULL
] = U [ 228ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm25_Cell_R_inne1 ; t1 [ 409ULL
] = 0.0 ; t1 [ 410ULL ] = U [ 230ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm26_Cell_R_inne1 ; t1 [ 411ULL
] = U [ 232ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm27_Cell_R_inne1 ; t1 [ 412ULL
] = 0.0 ; t1 [ 413ULL ] = U [ 234ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm28_Cell_R_inne1 ; t1 [ 414ULL
] = U [ 236ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm29_Cell_R_inne1 ; t1 [ 415ULL
] = 0.0 ; t1 [ 416ULL ] = U [ 238ULL ] * X [ 411ULL ] ; t1 [ 417ULL ] = U [
240ULL ] * X [ 444ULL ] ; t1 [ 418ULL ] = U [ 242ULL ] * X [ 446ULL ] ; t1 [
419ULL ] = 0.0 ; t1 [ 420ULL ] = U [ 244ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm32_Cell_R_inne1 ; t1 [ 421ULL
] = U [ 246ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm33_Cell_R_inne1 ; t1 [ 422ULL
] = 0.0 ; t1 [ 423ULL ] = U [ 248ULL ] * X [ 448ULL ] ; t1 [ 424ULL ] = U [
250ULL ] * X [ 450ULL ] ; t1 [ 425ULL ] = 0.0 ; t1 [ 426ULL ] = U [ 252ULL ]
* X [ 432ULL ] ; t1 [ 427ULL ] = U [ 254ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm37_Cell_R_inne1 ; t1 [ 428ULL
] = t2 / 625000.0 ; t1 [ 429ULL ] = U [ 256ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm38_Cell_R_inne1 ; t1 [ 430ULL
] = 0.0 ; t1 [ 431ULL ] = t2 / 625000.0 ; t1 [ 432ULL ] = U [ 258ULL ] * X [
452ULL ] ; t1 [ 433ULL ] = U [ 260ULL ] * X [ 259ULL ] ; t1 [ 434ULL ] = U [
262ULL ] * X [ 453ULL ] ; t1 [ 435ULL ] = 0.0 ; t1 [ 436ULL ] = U [ 264ULL ]
* X [ 435ULL ] ; t1 [ 437ULL ] = 0.0 ; t1 [ 438ULL ] = U [ 266ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm42_Cell_R_inne1 ; t1 [ 439ULL
] = U [ 268ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm43_Cell_R_inne1 ; t1 [ 440ULL
] = 0.0 ; t1 [ 441ULL ] = U [ 270ULL ] * X [ 455ULL ] ; t1 [ 442ULL ] = U [
272ULL ] * X [ 456ULL ] ; t1 [ 443ULL ] = 0.0 ; t1 [ 444ULL ] = U [ 274ULL ]
* X [ 438ULL ] ; t1 [ 445ULL ] = U [ 276ULL ] * X [ 441ULL ] ; t1 [ 446ULL ]
= 0.0 ; t1 [ 447ULL ] = U [ 278ULL ] *
BATTERIE_120S2P_73kWh_Subsystem2_Cell_elec_therm5_Cell_R_inner1 ; t1 [ 448ULL
] = U [ 280ULL ] * X [ 260ULL ] ; t1 [ 449ULL ] = U [ 282ULL ] * X [ 457ULL ]
; t1 [ 450ULL ] = U [ 284ULL ] * X [ 414ULL ] ; t1 [ 451ULL ] = U [ 286ULL ]
* X [ 417ULL ] ; t1 [ 452ULL ] = - 8.5878186968786974 ; t1 [ 453ULL ] = -
8.5878186968786974 ; t1 [ 454ULL ] = - 8.5878186968786974 ; t1 [ 455ULL ] = -
8.5878186968786974 ; t1 [ 456ULL ] = U [ 288ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm_Cell_R_inner_1 ; t1 [ 457ULL
] = U [ 290ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm1_Cell_R_inner1 ; t1 [ 458ULL
] = U [ 292ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm10_Cell_R_inne1 ; t1 [ 459ULL
] = U [ 294ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm11_Cell_R_inne1 ; t1 [ 460ULL
] = U [ 296ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm12_Cell_R_inne1 ; t1 [ 461ULL
] = U [ 298ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm13_Cell_R_inne1 ; t1 [ 462ULL
] = U [ 300ULL ] * X [ 487ULL ] ; t1 [ 463ULL ] = U [ 302ULL ] * X [ 489ULL ]
; t1 [ 464ULL ] = U [ 304ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm16_Cell_R_inne1 ; t1 [ 465ULL
] = U [ 306ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm17_Cell_R_inne1 ; t1 [ 466ULL
] = U [ 308ULL ] * X [ 491ULL ] ; t1 [ 467ULL ] = U [ 310ULL ] * X [ 493ULL ]
; t1 [ 468ULL ] = U [ 312ULL ] * X [ 475ULL ] ; t1 [ 469ULL ] = U [ 314ULL ]
* BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm20_Cell_R_inne1 ; t1 [
470ULL ] = t2 / 625000.0 ; t1 [ 471ULL ] = U [ 316ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm21_Cell_R_inne1 ; t1 [ 472ULL
] = t2 / 625000.0 ; t1 [ 473ULL ] = U [ 318ULL ] * X [ 495ULL ] ; t1 [ 474ULL
] = U [ 320ULL ] * X [ 496ULL ] ; t1 [ 475ULL ] = U [ 322ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm24_Cell_R_inne1 ; t1 [ 476ULL
] = U [ 324ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm25_Cell_R_inne1 ; t1 [ 477ULL
] = 0.0 ; t1 [ 478ULL ] = U [ 326ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm26_Cell_R_inne1 ; t1 [ 479ULL
] = U [ 328ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm27_Cell_R_inne1 ; t1 [ 480ULL
] = 0.0 ; t1 [ 481ULL ] = U [ 330ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm28_Cell_R_inne1 ; t1 [ 482ULL
] = U [ 332ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm29_Cell_R_inne1 ; t1 [ 483ULL
] = 0.0 ; t1 [ 484ULL ] = U [ 334ULL ] * X [ 478ULL ] ; t1 [ 485ULL ] = U [
336ULL ] * X [ 511ULL ] ; t1 [ 486ULL ] = U [ 338ULL ] * X [ 513ULL ] ; t1 [
487ULL ] = 0.0 ; t1 [ 488ULL ] = U [ 340ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm32_Cell_R_inne1 ; t1 [ 489ULL
] = U [ 342ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm33_Cell_R_inne1 ; t1 [ 490ULL
] = 0.0 ; t1 [ 491ULL ] = U [ 344ULL ] * X [ 515ULL ] ; t1 [ 492ULL ] = U [
346ULL ] * X [ 517ULL ] ; t1 [ 493ULL ] = 0.0 ; t1 [ 494ULL ] = U [ 348ULL ]
* X [ 499ULL ] ; t1 [ 495ULL ] = U [ 350ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm37_Cell_R_inne1 ; t1 [ 496ULL
] = t2 / 625000.0 ; t1 [ 497ULL ] = U [ 352ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm38_Cell_R_inne1 ; t1 [ 498ULL
] = 0.0 ; t1 [ 499ULL ] = t2 / 625000.0 ; t1 [ 500ULL ] = U [ 354ULL ] * X [
519ULL ] ; t1 [ 501ULL ] = U [ 356ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm4_Cell_R_inner1 ; t1 [ 502ULL
] = U [ 358ULL ] * X [ 520ULL ] ; t1 [ 503ULL ] = 0.0 ; t1 [ 504ULL ] = U [
360ULL ] * X [ 502ULL ] ; t1 [ 505ULL ] = 0.0 ; t1 [ 506ULL ] = U [ 362ULL ]
* BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm42_Cell_R_inne1 ; t1 [
507ULL ] = U [ 364ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm43_Cell_R_inne1 ; t1 [ 508ULL
] = 0.0 ; t1 [ 509ULL ] = U [ 366ULL ] * X [ 523ULL ] ; t1 [ 510ULL ] = U [
368ULL ] * X [ 524ULL ] ; t1 [ 511ULL ] = 0.0 ; t1 [ 512ULL ] = U [ 370ULL ]
* X [ 505ULL ] ; t1 [ 513ULL ] = U [ 372ULL ] * X [ 508ULL ] ; t1 [ 514ULL ]
= 0.0 ; t1 [ 515ULL ] = U [ 374ULL ] *
BATTERIE_120S2P_73kWh_Subsystem3_Cell_elec_therm5_Cell_R_inner1 ; t1 [ 516ULL
] = U [ 376ULL ] * X [ 522ULL ] ; t1 [ 517ULL ] = U [ 378ULL ] * X [ 525ULL ]
; t1 [ 518ULL ] = U [ 380ULL ] * X [ 481ULL ] ; t1 [ 519ULL ] = U [ 382ULL ]
* X [ 484ULL ] ; t1 [ 520ULL ] = - 8.5878186968786974 ; t1 [ 521ULL ] = -
8.5878186968786974 ; t1 [ 522ULL ] = - 8.5878186968786974 ; t1 [ 523ULL ] = -
8.5878186968786974 ; t1 [ 524ULL ] = U [ 384ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm_Cell_R_inner_1 ; t1 [ 525ULL
] = U [ 386ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm1_Cell_R_inner1 ; t1 [ 526ULL
] = U [ 388ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm10_Cell_R_inne1 ; t1 [ 527ULL
] = U [ 390ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm11_Cell_R_inne1 ; t1 [ 528ULL
] = U [ 392ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm12_Cell_R_inne1 ; t1 [ 529ULL
] = U [ 394ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm13_Cell_R_inne1 ; t1 [ 530ULL
] = U [ 396ULL ] * X [ 543ULL ] ; t1 [ 531ULL ] = U [ 398ULL ] * X [ 545ULL ]
; t1 [ 532ULL ] = U [ 400ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm16_Cell_R_inne1 ; t1 [ 533ULL
] = U [ 402ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm17_Cell_R_inne1 ; t1 [ 534ULL
] = U [ 404ULL ] * X [ 547ULL ] ; t1 [ 535ULL ] = U [ 406ULL ] * X [ 549ULL ]
; t1 [ 536ULL ] = U [ 408ULL ] * X [ 531ULL ] ; t1 [ 537ULL ] = U [ 410ULL ]
* BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm20_Cell_R_inne1 ; t1 [
538ULL ] = t2 / 625000.0 ; t1 [ 539ULL ] = U [ 412ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm21_Cell_R_inne1 ; t1 [ 540ULL
] = t2 / 625000.0 ; t1 [ 541ULL ] = U [ 414ULL ] * X [ 551ULL ] ; t1 [ 542ULL
] = U [ 416ULL ] * X [ 552ULL ] ; t1 [ 543ULL ] = U [ 418ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm24_Cell_R_inne1 ; t1 [ 544ULL
] = U [ 420ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm25_Cell_R_inne1 ; t1 [ 545ULL
] = 0.029102399999999994 ; t1 [ 546ULL ] = U [ 422ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm26_Cell_R_inne1 ; t1 [ 547ULL
] = U [ 424ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm27_Cell_R_inne1 ; t1 [ 548ULL
] = 0.029102399999999994 ; t1 [ 549ULL ] = U [ 426ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm28_Cell_R_inne1 ; t1 [ 550ULL
] = U [ 428ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm29_Cell_R_inne1 ; t1 [ 551ULL
] = 0.029102399999999994 ; t1 [ 552ULL ] = U [ 430ULL ] * X [ 534ULL ] ; t1 [
553ULL ] = U [ 432ULL ] * X [ 569ULL ] ; t1 [ 554ULL ] = U [ 434ULL ] * X [
572ULL ] ; t1 [ 555ULL ] = 0.029102399999999994 ; t1 [ 556ULL ] = U [ 436ULL
] * BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm32_Cell_R_inne1 ; t1 [
557ULL ] = U [ 438ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm33_Cell_R_inne1 ; t1 [ 558ULL
] = 0.029102399999999994 ; t1 [ 559ULL ] = U [ 440ULL ] * X [ 575ULL ] ; t1 [
560ULL ] = U [ 442ULL ] * X [ 578ULL ] ; t1 [ 561ULL ] = 0.029102399999999994
; t1 [ 562ULL ] = U [ 444ULL ] * X [ 555ULL ] ; t1 [ 563ULL ] = U [ 446ULL ]
* BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm37_Cell_R_inne1 ; t1 [
564ULL ] = t2 / 625000.0 ; t1 [ 565ULL ] = U [ 448ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm38_Cell_R_inne1 ; t1 [ 566ULL
] = 0.029102399999999994 ; t1 [ 567ULL ] = t2 / 625000.0 ; t1 [ 568ULL ] = U
[ 450ULL ] * X [ 581ULL ] ; t1 [ 569ULL ] = U [ 452ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm4_Cell_R_inner1 ; t1 [ 570ULL
] = U [ 454ULL ] * X [ 583ULL ] ; t1 [ 571ULL ] = 0.029102399999999994 ; t1 [
572ULL ] = U [ 456ULL ] * X [ 559ULL ] ; t1 [ 573ULL ] = 0.029102399999999994
; t1 [ 574ULL ] = U [ 458ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm42_Cell_R_inne1 ; t1 [ 575ULL
] = U [ 460ULL ] *
BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm43_Cell_R_inne1 ; t1 [ 576ULL
] = 0.029102399999999994 ; t1 [ 577ULL ] = U [ 462ULL ] * X [ 587ULL ] ; t1 [
578ULL ] = U [ 464ULL ] * X [ 589ULL ] ; t1 [ 579ULL ] = 0.029102399999999994
; t1 [ 580ULL ] = U [ 466ULL ] * X [ 562ULL ] ; t1 [ 581ULL ] = U [ 468ULL ]
* X [ 566ULL ] ; t1 [ 582ULL ] = 0.029102399999999994 ; t1 [ 583ULL ] = U [
470ULL ] * BATTERIE_120S2P_73kWh_Subsystem4_Cell_elec_therm5_Cell_R_inner1 ;
t1 [ 584ULL ] = U [ 472ULL ] * X [ 584ULL ] ; t1 [ 585ULL ] = U [ 474ULL ] *
X [ 592ULL ] ; t1 [ 586ULL ] = U [ 476ULL ] * X [ 537ULL ] ; t1 [ 587ULL ] =
U [ 478ULL ] * X [ 540ULL ] ; t1 [ 588ULL ] = - 8.5878186968786974 ; t1 [
589ULL ] = - 8.5878186968786974 ; t1 [ 590ULL ] = - 8.5878186968786974 ; t1 [
591ULL ] = - 8.5878186968786974 ; t1 [ 592ULL ] =
BMS_Partial_MOSFET_Ideal_Switching_mosfet_equation_i / 1.0E+6 ; for ( b = 0 ;
b < 593 ; b ++ ) { out . mX [ b ] = t1 [ b ] ; } ( void ) sys ; ( void ) t4 ;
return 0 ; }
