#include "__cf_Model_120S2P.h"
#include "ne_ds.h"
#include "Model_120S2P_bbd9d557_1_ds_tduf_p.h"
#include "Model_120S2P_bbd9d557_1_ds_sys_struct.h"
#include "Model_120S2P_bbd9d557_1_ds_externals.h"
#include "Model_120S2P_bbd9d557_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Model_120S2P_bbd9d557_1_ds_tduf_p ( const NeDynamicSystem * sys ,
const NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmSparsityPattern
out ; int32_T b ; static int32_T _cg_const_1 [ 482 ] = { 0 , 2 , 3 , 5 , 6 ,
8 , 9 , 11 , 12 , 14 , 15 , 17 , 18 , 20 , 21 , 23 , 24 , 26 , 27 , 29 , 30 ,
32 , 33 , 35 , 36 , 38 , 39 , 41 , 42 , 44 , 45 , 47 , 48 , 50 , 51 , 53 , 54
, 56 , 57 , 59 , 60 , 62 , 63 , 65 , 66 , 68 , 69 , 71 , 72 , 74 , 75 , 77 ,
78 , 80 , 81 , 83 , 84 , 86 , 87 , 89 , 90 , 92 , 93 , 95 , 96 , 98 , 99 ,
101 , 102 , 104 , 105 , 107 , 108 , 110 , 111 , 113 , 114 , 116 , 117 , 119 ,
120 , 122 , 123 , 125 , 126 , 128 , 129 , 131 , 132 , 134 , 135 , 137 , 138 ,
140 , 141 , 143 , 144 , 146 , 147 , 149 , 150 , 152 , 153 , 155 , 156 , 158 ,
159 , 161 , 162 , 164 , 165 , 167 , 168 , 170 , 171 , 173 , 174 , 176 , 177 ,
179 , 180 , 182 , 183 , 185 , 186 , 188 , 189 , 191 , 192 , 194 , 195 , 197 ,
198 , 200 , 201 , 203 , 204 , 206 , 207 , 209 , 210 , 212 , 213 , 215 , 216 ,
218 , 219 , 221 , 222 , 224 , 225 , 227 , 228 , 230 , 231 , 233 , 234 , 236 ,
237 , 239 , 240 , 242 , 243 , 245 , 246 , 248 , 249 , 251 , 252 , 254 , 255 ,
257 , 258 , 260 , 261 , 263 , 264 , 266 , 267 , 269 , 270 , 272 , 273 , 275 ,
276 , 278 , 279 , 281 , 282 , 284 , 285 , 287 , 288 , 290 , 291 , 293 , 294 ,
296 , 297 , 299 , 300 , 302 , 303 , 305 , 306 , 308 , 309 , 311 , 312 , 314 ,
315 , 317 , 318 , 320 , 321 , 323 , 324 , 326 , 327 , 329 , 330 , 332 , 333 ,
335 , 336 , 338 , 339 , 341 , 342 , 344 , 345 , 347 , 348 , 350 , 351 , 353 ,
354 , 356 , 357 , 359 , 360 , 362 , 363 , 365 , 366 , 368 , 369 , 371 , 372 ,
374 , 375 , 377 , 378 , 380 , 381 , 383 , 384 , 386 , 387 , 389 , 390 , 392 ,
393 , 395 , 396 , 398 , 399 , 401 , 402 , 404 , 405 , 407 , 408 , 410 , 411 ,
413 , 414 , 416 , 417 , 419 , 420 , 422 , 423 , 425 , 426 , 428 , 429 , 431 ,
432 , 434 , 435 , 437 , 438 , 440 , 441 , 443 , 444 , 446 , 447 , 449 , 450 ,
452 , 453 , 455 , 456 , 458 , 459 , 461 , 462 , 464 , 465 , 467 , 468 , 470 ,
471 , 473 , 474 , 476 , 477 , 479 , 480 , 482 , 483 , 485 , 486 , 488 , 489 ,
491 , 492 , 494 , 495 , 497 , 498 , 500 , 501 , 503 , 504 , 506 , 507 , 509 ,
510 , 512 , 513 , 515 , 516 , 518 , 519 , 521 , 522 , 524 , 525 , 527 , 528 ,
530 , 531 , 533 , 534 , 536 , 537 , 539 , 540 , 542 , 543 , 545 , 546 , 548 ,
549 , 551 , 552 , 554 , 555 , 557 , 558 , 560 , 561 , 563 , 564 , 566 , 567 ,
569 , 570 , 572 , 573 , 575 , 576 , 578 , 579 , 581 , 582 , 584 , 585 , 587 ,
588 , 590 , 591 , 593 , 594 , 596 , 597 , 599 , 600 , 602 , 603 , 605 , 606 ,
608 , 609 , 611 , 612 , 614 , 615 , 617 , 618 , 620 , 621 , 623 , 624 , 626 ,
627 , 629 , 630 , 632 , 633 , 635 , 636 , 638 , 639 , 641 , 642 , 644 , 645 ,
647 , 648 , 650 , 651 , 653 , 654 , 656 , 657 , 659 , 660 , 662 , 663 , 665 ,
666 , 668 , 669 , 671 , 672 , 674 , 675 , 677 , 678 , 680 , 681 , 683 , 684 ,
686 , 687 , 689 , 690 , 692 , 693 , 695 , 696 , 698 , 699 , 701 , 702 , 704 ,
705 , 707 , 708 , 710 , 711 , 713 , 714 , 716 , 717 , 719 , 720 , 721 } ;
static int32_T _cg_const_2 [ 721 ] = { 0 , 240 , 240 , 1 , 241 , 241 , 2 ,
242 , 242 , 3 , 243 , 243 , 4 , 244 , 244 , 5 , 245 , 245 , 6 , 246 , 246 , 7
, 247 , 247 , 8 , 248 , 248 , 9 , 249 , 249 , 10 , 250 , 250 , 11 , 251 , 251
, 12 , 252 , 252 , 13 , 253 , 253 , 14 , 255 , 255 , 15 , 257 , 257 , 16 ,
258 , 258 , 17 , 259 , 259 , 18 , 260 , 260 , 19 , 262 , 262 , 20 , 263 , 263
, 21 , 265 , 265 , 22 , 266 , 266 , 23 , 268 , 268 , 24 , 269 , 269 , 25 ,
270 , 270 , 26 , 272 , 272 , 27 , 273 , 273 , 28 , 275 , 275 , 29 , 276 , 276
, 30 , 278 , 278 , 31 , 279 , 279 , 32 , 281 , 281 , 33 , 284 , 284 , 34 ,
285 , 285 , 35 , 286 , 286 , 36 , 288 , 288 , 37 , 290 , 290 , 38 , 291 , 291
, 39 , 293 , 293 , 40 , 294 , 294 , 41 , 296 , 296 , 42 , 297 , 297 , 43 ,
299 , 299 , 44 , 300 , 300 , 45 , 301 , 301 , 46 , 302 , 302 , 47 , 303 , 303
, 48 , 320 , 320 , 49 , 321 , 321 , 50 , 322 , 322 , 51 , 323 , 323 , 52 ,
324 , 324 , 53 , 325 , 325 , 54 , 326 , 326 , 55 , 327 , 327 , 56 , 328 , 328
, 57 , 329 , 329 , 58 , 330 , 330 , 59 , 331 , 331 , 60 , 332 , 332 , 61 ,
333 , 333 , 62 , 335 , 335 , 63 , 337 , 337 , 64 , 338 , 338 , 65 , 339 , 339
, 66 , 340 , 340 , 67 , 342 , 342 , 68 , 343 , 343 , 69 , 345 , 345 , 70 ,
346 , 346 , 71 , 348 , 348 , 72 , 349 , 349 , 73 , 350 , 350 , 74 , 352 , 352
, 75 , 353 , 353 , 76 , 355 , 355 , 77 , 356 , 356 , 78 , 358 , 358 , 79 ,
359 , 359 , 80 , 361 , 361 , 81 , 364 , 364 , 82 , 365 , 365 , 83 , 366 , 366
, 84 , 368 , 368 , 85 , 370 , 370 , 86 , 371 , 371 , 87 , 373 , 373 , 88 ,
374 , 374 , 89 , 376 , 376 , 90 , 377 , 377 , 91 , 379 , 379 , 92 , 380 , 380
, 93 , 381 , 381 , 94 , 382 , 382 , 95 , 383 , 383 , 96 , 388 , 388 , 97 ,
389 , 389 , 98 , 390 , 390 , 99 , 391 , 391 , 100 , 392 , 392 , 101 , 393 ,
393 , 102 , 394 , 394 , 103 , 395 , 395 , 104 , 396 , 396 , 105 , 397 , 397 ,
106 , 398 , 398 , 107 , 399 , 399 , 108 , 400 , 400 , 109 , 401 , 401 , 110 ,
403 , 403 , 111 , 405 , 405 , 112 , 406 , 406 , 113 , 407 , 407 , 114 , 408 ,
408 , 115 , 410 , 410 , 116 , 411 , 411 , 117 , 413 , 413 , 118 , 414 , 414 ,
119 , 416 , 416 , 120 , 417 , 417 , 121 , 418 , 418 , 122 , 420 , 420 , 123 ,
421 , 421 , 124 , 423 , 423 , 125 , 424 , 424 , 126 , 426 , 426 , 127 , 427 ,
427 , 128 , 429 , 429 , 129 , 432 , 432 , 130 , 433 , 433 , 131 , 434 , 434 ,
132 , 436 , 436 , 133 , 438 , 438 , 134 , 439 , 439 , 135 , 441 , 441 , 136 ,
442 , 442 , 137 , 444 , 444 , 138 , 445 , 445 , 139 , 447 , 447 , 140 , 448 ,
448 , 141 , 449 , 449 , 142 , 450 , 450 , 143 , 451 , 451 , 144 , 456 , 456 ,
145 , 457 , 457 , 146 , 458 , 458 , 147 , 459 , 459 , 148 , 460 , 460 , 149 ,
461 , 461 , 150 , 462 , 462 , 151 , 463 , 463 , 152 , 464 , 464 , 153 , 465 ,
465 , 154 , 466 , 466 , 155 , 467 , 467 , 156 , 468 , 468 , 157 , 469 , 469 ,
158 , 471 , 471 , 159 , 473 , 473 , 160 , 474 , 474 , 161 , 475 , 475 , 162 ,
476 , 476 , 163 , 478 , 478 , 164 , 479 , 479 , 165 , 481 , 481 , 166 , 482 ,
482 , 167 , 484 , 484 , 168 , 485 , 485 , 169 , 486 , 486 , 170 , 488 , 488 ,
171 , 489 , 489 , 172 , 491 , 491 , 173 , 492 , 492 , 174 , 494 , 494 , 175 ,
495 , 495 , 176 , 497 , 497 , 177 , 500 , 500 , 178 , 501 , 501 , 179 , 502 ,
502 , 180 , 504 , 504 , 181 , 506 , 506 , 182 , 507 , 507 , 183 , 509 , 509 ,
184 , 510 , 510 , 185 , 512 , 512 , 186 , 513 , 513 , 187 , 515 , 515 , 188 ,
516 , 516 , 189 , 517 , 517 , 190 , 518 , 518 , 191 , 519 , 519 , 192 , 524 ,
524 , 193 , 525 , 525 , 194 , 526 , 526 , 195 , 527 , 527 , 196 , 528 , 528 ,
197 , 529 , 529 , 198 , 530 , 530 , 199 , 531 , 531 , 200 , 532 , 532 , 201 ,
533 , 533 , 202 , 534 , 534 , 203 , 535 , 535 , 204 , 536 , 536 , 205 , 537 ,
537 , 206 , 539 , 539 , 207 , 541 , 541 , 208 , 542 , 542 , 209 , 543 , 543 ,
210 , 544 , 544 , 211 , 546 , 546 , 212 , 547 , 547 , 213 , 549 , 549 , 214 ,
550 , 550 , 215 , 552 , 552 , 216 , 553 , 553 , 217 , 554 , 554 , 218 , 556 ,
556 , 219 , 557 , 557 , 220 , 559 , 559 , 221 , 560 , 560 , 222 , 562 , 562 ,
223 , 563 , 563 , 224 , 565 , 565 , 225 , 568 , 568 , 226 , 569 , 569 , 227 ,
570 , 570 , 228 , 572 , 572 , 229 , 574 , 574 , 230 , 575 , 575 , 231 , 577 ,
577 , 232 , 578 , 578 , 233 , 580 , 580 , 234 , 581 , 581 , 235 , 583 , 583 ,
236 , 584 , 584 , 237 , 585 , 585 , 238 , 586 , 586 , 239 , 587 , 587 , 592 }
; ( void ) t1 ; out = t2 -> mTDUF_P ; out . mNumCol = 481ULL ; out . mNumRow
= 593ULL ; for ( b = 0 ; b < 482 ; b ++ ) { out . mJc [ b ] = _cg_const_1 [ b
] ; } for ( b = 0 ; b < 721 ; b ++ ) { out . mIr [ b ] = _cg_const_2 [ b ] ;
} ( void ) sys ; ( void ) t2 ; return 0 ; }