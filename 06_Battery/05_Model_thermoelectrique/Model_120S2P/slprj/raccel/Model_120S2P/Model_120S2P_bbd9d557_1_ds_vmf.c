#include "__cf_Model_120S2P.h"
#include "ne_ds.h"
#include "Model_120S2P_bbd9d557_1_ds_vmf.h"
#include "Model_120S2P_bbd9d557_1_ds_sys_struct.h"
#include "Model_120S2P_bbd9d557_1_ds_externals.h"
#include "Model_120S2P_bbd9d557_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Model_120S2P_bbd9d557_1_ds_vmf ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ;
boolean_T t0 [ 593 ] ; int32_T b ; static boolean_T _cg_const_1 [ 593 ] = {
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , true ,
true , false , true , false , true , true , true , true , false , true , true
, false , true , true , false , true , true , true , false , true , true ,
false , true , true , false , true , true , false , true , false , false ,
true , true , true , false , true , false , true , true , false , true , true
, false , true , true , false , true , true , true , true , true , false ,
false , false , false , false , false , false , false , false , false , false
, false , false , false , false , false , true , true , true , true , true ,
true , true , true , true , true , true , true , true , true , false , true ,
false , true , true , true , true , false , true , true , false , true , true
, false , true , true , true , false , true , true , false , true , true ,
false , true , true , false , true , false , false , true , true , true ,
false , true , false , true , true , false , true , true , false , true ,
true , false , true , true , true , true , true , false , false , false ,
false , true , true , true , true , true , true , true , true , true , true ,
true , true , true , true , false , true , false , true , true , true , true
, false , true , true , false , true , true , false , true , true , true ,
false , true , true , false , true , true , false , true , true , false ,
true , false , false , true , true , true , false , true , false , true ,
true , false , true , true , false , true , true , false , true , true , true
, true , true , false , false , false , false , true , true , true , true ,
true , true , true , true , true , true , true , true , true , true , false ,
true , false , true , true , true , true , false , true , true , false , true
, true , false , true , true , true , false , true , true , false , true ,
true , false , true , true , false , true , false , false , true , true ,
true , false , true , false , true , true , false , true , true , false ,
true , true , false , true , true , true , true , true , false , false ,
false , false , true , true , true , true , true , true , true , true , true
, true , true , true , true , true , false , true , false , true , true ,
true , true , false , true , true , false , true , true , false , true , true
, true , false , true , true , false , true , true , false , true , true ,
false , true , false , false , true , true , true , false , true , false ,
true , true , false , true , true , false , true , true , false , true , true
, true , true , true , false , false , false , false , true } ; ( void ) t1 ;
out = t2 -> mVMF ; for ( b = 0 ; b < 593 ; b ++ ) { t0 [ b ] = _cg_const_1 [
b ] ; } for ( b = 0 ; b < 593 ; b ++ ) { out . mX [ b ] = t0 [ b ] ; } ( void
) sys ; ( void ) t2 ; return 0 ; }
