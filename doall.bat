rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 100000 0 3252" "tests\90" 90
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 100000 0 8892" "tests\91" 91
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 100000 1 2572" "tests\92" 92
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 100000 1 2952" "tests\93" 93
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 100 0 1652" "tests\94" 94
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 1000 0 7592" "tests\95" 95
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 10000 1 3472" "tests\96" 96
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 23874 100000 100000" "tests\97" 97
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 3874 90000 100000" "tests\98" 98
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 2874 90000 100000" "tests\99" 99
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 2374 90000 100000" "tests\100" 100
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 2384 90000 100000" "tests\101" 101
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 12345 25" "tests\102" 102
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 31415 100" "tests\103" 103
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 1357 1000" "tests\104" 104
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 2718 10000" "tests\105" 105
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 99 100000" "tests\106" 106
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 700 99782" "tests\107" 107
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 2013 87439" "tests\108" 108
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 1 99999" "tests\109" 109
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 29999 98765" "tests\110" 110
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 777 777" "tests\111" 111
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 12345 25" "tests\112" 112
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 31415 100" "tests\113" 113
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 1357 1000" "tests\114" 114
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 2718 10000" "tests\115" 115
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 99 100000" "tests\116" 116
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 700 99782" "tests\117" 117
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 2013 87439" "tests\118" 118
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 1 99999" "tests\119" 119
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 29999 98765" "tests\120" 120
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 777 777" "tests\121" 121
call scripts\gen-input-via-stdout.bat "files\31pal_gen1.exe 300000 1 2952" "tests\122" 122
call scripts\gen-input-via-stdout.bat "files\31pal_gen.exe 238741 300000 300000" "tests\123" 123
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abab.exe 321415 300000" "tests\124" 124
call scripts\gen-input-via-stdout.bat "files\31pal_gen_ab.exe 12345 300000" "tests\125" 125
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt_noise.exe 300000 23841" "tests\126" 126
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt_noise.exe 300000 23842" "tests\127" 127
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt_noise.exe 300000 23843" "tests\128" 128
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt_noise.exe 300000 23844" "tests\129" 129
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt.exe 300000 3841" "tests\130" 130
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt.exe 300000 2842" "tests\131" 131
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt.exe 300000 2343" "tests\132" 132
call scripts\gen-input-via-stdout.bat "files\31pal_gen_sqrt.exe 300000 2384" "tests\133" 133
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abc.exe 300000" "tests\134" 134
call scripts\gen-input-via-stdout.bat "files\31pal_gen_abacaba.exe" "tests\135" 135
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 100000 0 3252" "tests\136" 136
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 100000 0 8892" "tests\137" 137
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 100000 1 2572" "tests\138" 138
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 100000 1 2952" "tests\139" 139
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 100 0 1652" "tests\140" 140
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 1000 0 7592" "tests\141" 141
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 10000 1 3472" "tests\142" 142
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 23874 100000 100000" "tests\143" 143
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 3874 90000 100000" "tests\144" 144
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 2874 90000 100000" "tests\145" 145
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 2374 90000 100000" "tests\146" 146
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 2384 90000 100000" "tests\147" 147
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 12345 25" "tests\148" 148
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 31415 100" "tests\149" 149
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 1357 1000" "tests\150" 150
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 2718 10000" "tests\151" 151
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 99 100000" "tests\152" 152
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 700 99782" "tests\153" 153
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 2013 87439" "tests\154" 154
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 1 99999" "tests\155" 155
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 29999 98765" "tests\156" 156
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 777 777" "tests\157" 157
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 12345 25" "tests\158" 158
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 31415 100" "tests\159" 159
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 1357 1000" "tests\160" 160
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 2718 10000" "tests\161" 161
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 99 100000" "tests\162" 162
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 700 99782" "tests\163" 163
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 2013 87439" "tests\164" 164
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 1 99999" "tests\165" 165
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 29999 98765" "tests\166" 166
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 777 777" "tests\167" 167
call scripts\gen-input-via-stdout.bat "files\100500_gen1.exe 300000 1 2952" "tests\168" 168
call scripts\gen-input-via-stdout.bat "files\100500_gen.exe 238741 300000 300000" "tests\169" 169
call scripts\gen-input-via-stdout.bat "files\100500_gen_abab.exe 321415 300000" "tests\170" 170
call scripts\gen-input-via-stdout.bat "files\100500_gen_ab.exe 12345 300000" "tests\171" 171
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt_noise.exe 300000 23841" "tests\172" 172
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt_noise.exe 300000 23842" "tests\173" 173
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt_noise.exe 300000 23843" "tests\174" 174
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt_noise.exe 300000 23844" "tests\175" 175
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt.exe 300000 3841" "tests\176" 176
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt.exe 300000 2842" "tests\177" 177
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt.exe 300000 2343" "tests\178" 178
call scripts\gen-input-via-stdout.bat "files\100500_gen_sqrt.exe 300000 2384" "tests\179" 179
call scripts\gen-input-via-stdout.bat "files\100500_gen_abc.exe 300000" "tests\180" 180
call scripts\gen-input-via-stdout.bat "files\100500_gen_abacaba.exe" "tests\181" 181
call scripts\gen-input-via-stdout.bat "files\five_gen_abacaba.exe" "tests\182" 182
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 100000 0 3252" "tests\183" 183
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 100000 0 8892" "tests\184" 184
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 100000 1 2572" "tests\185" 185
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 100000 1 2952" "tests\186" 186
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 100 0 1652" "tests\187" 187
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 1000 0 7592" "tests\188" 188
call scripts\gen-input-via-stdout.bat "files\five_gen1.exe 10000 1 3472" "tests\189" 189
call scripts\gen-input-via-stdout.bat "files\five_gen.exe 23874 100000 100000" "tests\190" 190
call scripts\gen-input-via-stdout.bat "files\five_gen.exe 3874 90000 100000" "tests\191" 191
call scripts\gen-input-via-stdout.bat "files\five_gen.exe 2874 90000 100000" "tests\192" 192
call scripts\gen-input-via-stdout.bat "files\five_gen.exe 2374 90000 100000" "tests\193" 193
call scripts\gen-input-via-stdout.bat "files\five_gen.exe 2384 90000 100000" "tests\194" 194
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 12345 25" "tests\195" 195
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 31415 100" "tests\196" 196
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 1357 1000" "tests\197" 197
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 2718 10000" "tests\198" 198
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 99 100000" "tests\199" 199
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 700 99782" "tests\200" 200
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 2013 87439" "tests\201" 201
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 1 99999" "tests\202" 202
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 29999 98765" "tests\203" 203
call scripts\gen-input-via-stdout.bat "files\five_gen_abab.exe 777 777" "tests\204" 204
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 12345 25" "tests\205" 205
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 31415 100" "tests\206" 206
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 1357 1000" "tests\207" 207
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 2718 10000" "tests\208" 208
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 99 100000" "tests\209" 209
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 700 99782" "tests\210" 210
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 2013 87439" "tests\211" 211
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 1 99999" "tests\212" 212
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 29999 98765" "tests\213" 213
call scripts\gen-input-via-stdout.bat "files\five_gen_ab.exe 777 777" "tests\214" 214
call scripts\gen-input-via-stdout.bat "files\mnem_gen_aaaaaa.exe a 100" "tests\215" 215
call scripts\gen-input-via-stdout.bat "files\mnem_gen_ababa.exe a b 67" "tests\216" 216
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe ab 42" "tests\217" 217
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe abc 21" "tests\218" 218
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe aaba 100" "tests\219" 219
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe entaroadun 10" "tests\220" 220
call scripts\gen-input-via-stdout.bat "files\mnem_gen_fibonacci.exe a b 7" "tests\221" 221
call scripts\gen-input-via-stdout.bat "files\mnem_gen_fibonacci.exe b a 10" "tests\222" 222
call scripts\gen-input-via-stdout.bat "files\mnem_gen_abacaba.exe 6" "tests\223" 223
call scripts\gen-input-via-stdout.bat "files\mnem_gen_yap.exe 5 16021986" "tests\224" 224
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 2 87 16021986" "tests\225" 225
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 3 89 16021986" "tests\226" 226
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 26 101 16021986" "tests\227" 227
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 2 99 16021986" "tests\228" 228
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 4 100 16021986" "tests\229" 229
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 26 98 16021986" "tests\230" 230
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe a b 98" "tests\231" 231
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe b a 99" "tests\232" 232
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe r s 100" "tests\233" 233
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube1.exe a b c 3995" "tests\234" 234
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube1.exe x y z 3996" "tests\235" 235
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube1.exe q x z 3997" "tests\236" 236
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube2.exe a b c d e 3998" "tests\237" 237
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube2.exe i j k l m 3999" "tests\238" 238
call scripts\gen-input-via-stdout.bat "files\mnem_gen_anticube2.exe r s t z x 4000" "tests\239" 239
call scripts\gen-input-via-stdout.bat "files\mnem_gen_aaaaaa.exe w 1001" "tests\240" 240
call scripts\gen-input-via-stdout.bat "files\mnem_gen_ababa.exe x y 430" "tests\241" 241
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe ijk 359" "tests\242" 242
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe aababb 166" "tests\243" 243
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe aduntoridas 90" "tests\244" 244
call scripts\gen-input-via-stdout.bat "files\mnem_gen_fibonacci.exe k l 12" "tests\245" 245
call scripts\gen-input-via-stdout.bat "files\mnem_gen_fibonacci.exe i j 15" "tests\246" 246
call scripts\gen-input-via-stdout.bat "files\mnem_gen_abacaba.exe 10" "tests\247" 247
call scripts\gen-input-via-stdout.bat "files\mnem_gen_yap.exe 8 16021986" "tests\248" 248
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 2 997 16021986" "tests\249" 249
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 5 900 16021986" "tests\250" 250
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 16 1000 16021986" "tests\251" 251
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 2 998 16021986" "tests\252" 252
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 11 991 16021986" "tests\253" 253
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 26 1000 16021986" "tests\254" 254
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe a b 996" "tests\255" 255
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe a z 997" "tests\256" 256
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe x z 1001" "tests\257" 257
call scripts\gen-input-via-stdout.bat "files\mnem_gen_aaaaaa.exe z 4000" "tests\258" 258
call scripts\gen-input-via-stdout.bat "files\mnem_gen_ababa.exe q x 1999" "tests\259" 259
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe qxx 1333" "tests\260" 260
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe qxz 1333" "tests\261" 261
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe aababb 666" "tests\262" 262
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe abracadabra 363" "tests\263" 263
call scripts\gen-input-via-stdout.bat "files\mnem_gen_periodic.exe stupidbastard 307" "tests\264" 264
call scripts\gen-input-via-stdout.bat "files\mnem_gen_fibonacci.exe z x 17" "tests\265" 265
call scripts\gen-input-via-stdout.bat "files\mnem_gen_abacaba.exe 11" "tests\266" 266
call scripts\gen-input-via-stdout.bat "files\mnem_gen_yap.exe 10 16021986" "tests\267" 267
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 2 4000 16021986" "tests\268" 268
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 3 4000 16021986" "tests\269" 269
call scripts\gen-input-via-stdout.bat "files\mnem_gen_rand.exe 26 4000 16021986" "tests\270" 270
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 2 3998 16021986" "tests\271" 271
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 4 3997 16021986" "tests\272" 272
call scripts\gen-input-via-stdout.bat "files\mnem_gen_palindrome.exe 26 4000 16021986" "tests\273" 273
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe a b 4000" "tests\274" 274
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe q x 3999" "tests\275" 275
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe i j 3998" "tests\276" 276
call scripts\gen-input-via-stdout.bat "files\mnem_gen_maxans.exe k l 3997" "tests\277" 277
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 100000 0 3252" "tests\278" 278
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 100000 0 8892" "tests\279" 279
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 100000 1 2572" "tests\280" 280
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 100000 1 2952" "tests\281" 281
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 100 0 1652" "tests\282" 282
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 1000 0 7592" "tests\283" 283
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 10000 1 3472" "tests\284" 284
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 23874 100000 100000" "tests\285" 285
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 3874 90000 100000" "tests\286" 286
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 2874 90000 100000" "tests\287" 287
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 2374 90000 100000" "tests\288" 288
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 2384 90000 100000" "tests\289" 289
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 12345 25" "tests\290" 290
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 31415 100" "tests\291" 291
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 1357 1000" "tests\292" 292
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 2718 10000" "tests\293" 293
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 99 100000" "tests\294" 294
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 700 99782" "tests\295" 295
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 2013 87439" "tests\296" 296
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 1 99999" "tests\297" 297
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 29999 98765" "tests\298" 298
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 777 777" "tests\299" 299
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 12345 25" "tests\300" 300
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 31415 100" "tests\301" 301
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 1357 1000" "tests\302" 302
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 2718 10000" "tests\303" 303
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 99 100000" "tests\304" 304
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 700 99782" "tests\305" 305
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 2013 87439" "tests\306" 306
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 1 99999" "tests\307" 307
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 29999 98765" "tests\308" 308
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 777 777" "tests\309" 309
call scripts\gen-input-via-stdout.bat "files\pairs_gen1.exe 300000 1 2952" "tests\310" 310
call scripts\gen-input-via-stdout.bat "files\pairs_gen.exe 238741 300000 300000" "tests\311" 311
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abab.exe 321415 300000" "tests\312" 312
call scripts\gen-input-via-stdout.bat "files\pairs_gen_ab.exe 12345 300000" "tests\313" 313
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt_noise.exe 300000 23841" "tests\314" 314
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt_noise.exe 300000 23842" "tests\315" 315
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt_noise.exe 300000 23843" "tests\316" 316
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt_noise.exe 300000 23844" "tests\317" 317
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt.exe 300000 3841" "tests\318" 318
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt.exe 300000 2842" "tests\319" 319
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt.exe 300000 2343" "tests\320" 320
call scripts\gen-input-via-stdout.bat "files\pairs_gen_sqrt.exe 300000 2384" "tests\321" 321
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abc.exe 300000" "tests\322" 322
call scripts\gen-input-via-stdout.bat "files\pairs_gen_abacaba.exe" "tests\323" 323
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 8 123" "tests\324" 324
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 9 42" "tests\325" 325
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 11 13" "tests\326" 326
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 15 613" "tests\327" 327
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 15 228" "tests\328" 328
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 15 230" "tests\329" 329
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 15 333" "tests\330" 330
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 15 334" "tests\331" 331
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 15 10 231" "tests\332" 332
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 15 10 232" "tests\333" 333
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3 11 10" "tests\334" 334
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4 13 15" "tests\335" 335
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 5 15 26" "tests\336" 336
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 8 11 10" "tests\337" 337
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 9 13 15" "tests\338" 338
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 10 15 26" "tests\339" 339
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 49 39" "tests\340" 340
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 129 132" "tests\341" 341
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 199 14" "tests\342" 342
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 299 65535" "tests\343" 343
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 300 555" "tests\344" 344
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 300 556" "tests\345" 345
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 300 557" "tests\346" 346
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 300 558" "tests\347" 347
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 300 10 559" "tests\348" 348
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 300 10 560" "tests\349" 349
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 103 150 10" "tests\350" 350
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 104 200 15" "tests\351" 351
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 105 300 26" "tests\352" 352
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 108 150 10" "tests\353" 353
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 109 200 15" "tests\354" 354
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 110 300 26" "tests\355" 355
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 3000 569" "tests\356" 356
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 3000 570" "tests\357" 357
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 3000 5 571" "tests\358" 358
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3002 2500 26" "tests\359" 359
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3003 2900 26" "tests\360" 360
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3004 2990 26" "tests\361" 361
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3005 2991 26" "tests\362" 362
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3006 2993 26" "tests\363" 363
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3007 2997 26" "tests\364" 364
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3008 2999 26" "tests\365" 365
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3009 3000 26" "tests\366" 366
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3010 3000 26" "tests\367" 367
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 1999 666" "tests\368" 368
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 2499 777" "tests\369" 369
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 2799 101" "tests\370" 370
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 2999 111" "tests\371" 371
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 1 3000 601" "tests\372" 372
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 3000 602" "tests\373" 373
call scripts\gen-input-via-stdout.bat "files\split_gen_many_same.exe 3000 5 603" "tests\374" 374
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3502 2500 26" "tests\375" 375
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3503 2900 26" "tests\376" 376
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3504 2990 26" "tests\377" 377
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3505 2991 26" "tests\378" 378
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3506 2993 26" "tests\379" 379
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3507 2997 26" "tests\380" 380
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3508 2999 26" "tests\381" 381
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3509 3000 26" "tests\382" 382
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 3510 3000 26" "tests\383" 383
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 200000 999" "tests\384" 384
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4002 150000 26" "tests\385" 385
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4003 190000 26" "tests\386" 386
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4004 199500 26" "tests\387" 387
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4005 199579 26" "tests\388" 388
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4006 199933 26" "tests\389" 389
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4007 199986 26" "tests\390" 390
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4008 199991 26" "tests\391" 391
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4009 200000 26" "tests\392" 392
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4010 200000 26" "tests\393" 393
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 99999 123" "tests\394" 394
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 149999 321" "tests\395" 395
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 169999 5" "tests\396" 396
call scripts\gen-input-via-stdout.bat "files\split_gen_anti_greedy.exe 199999 6" "tests\397" 397
call scripts\gen-input-via-stdout.bat "files\split_gen_pattern.exe 3 200000 998" "tests\398" 398
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4502 150000 26" "tests\399" 399
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4503 190000 26" "tests\400" 400
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4504 199500 26" "tests\401" 401
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4505 199579 26" "tests\402" 402
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4506 199933 26" "tests\403" 403
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4507 199986 26" "tests\404" 404
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4508 199991 26" "tests\405" 405
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4509 200000 26" "tests\406" 406
call scripts\gen-input-via-stdout.bat "files\split_gen.exe 4510 200000 26" "tests\407" 407
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe" "tests\408" 408
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe bc" "tests\409" 409
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe ac" "tests\410" 410
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe sd" "tests\411" 411
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe az" "tests\412" 412
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe dk" "tests\413" 413
call scripts\gen-input-via-stdout.bat "files\sverkh_antihash.exe el" "tests\414" 414
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring.exe" "tests\415" 415
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring.exe 3568" "tests\416" 416
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring.exe 7326" "tests\417" 417
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring.exe 2853" "tests\418" 418
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring.exe 9427" "tests\419" 419
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring2.exe" "tests\420" 420
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring2.exe 3568" "tests\421" 421
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring2.exe 7326" "tests\422" 422
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring2.exe 2853" "tests\423" 423
call scripts\gen-input-via-stdout.bat "files\sverkh_genbadstring2.exe 9427" "tests\424" 424
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe a" "tests\425" 425
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe ab" "tests\426" 426
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe abc" "tests\427" 427
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe babacab" "tests\428" 428
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe abcbcbcbcabcbcbcabcbcabc" "tests\429" 429
call scripts\gen-input-via-stdout.bat "files\sverkh_genmul.exe abacabadabacabaeabacabadabacabazx" "tests\430" 430
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe" "tests\431" 431
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 3568" "tests\432" 432
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 7326" "tests\433" 433
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 2853" "tests\434" 434
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 9427" "tests\435" 435
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 35681" "tests\436" 436
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 73261" "tests\437" 437
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 28531" "tests\438" 438
call scripts\gen-input-via-stdout.bat "files\sverkh_rnd.exe 94271" "tests\439" 439
call scripts\gen-input-via-stdout.bat "files\sverkh_genbitnumbers.exe 234 100" "tests\440" 440
call scripts\gen-input-via-stdout.bat "files\sverkh_genbitnumbers.exe 123 1000" "tests\441" 441
call scripts\gen-input-via-stdout.bat "files\sverkh_genbitnumbers.exe 98984 10000" "tests\442" 442
call scripts\gen-input-via-stdout.bat "files\sverkh_genbitnumbers.exe 23421 50000" "tests\443" 443
call scripts\gen-input-via-stdout.bat "files\sverkh_genbitnumbers.exe 23487 100000" "tests\444" 444
call scripts\gen-input-via-stdout.bat "files\sverkh_genabstring.exe 123 1000 10" "tests\445" 445
call scripts\gen-input-via-stdout.bat "files\sverkh_genabstring.exe 456 10000 5" "tests\446" 446
call scripts\gen-input-via-stdout.bat "files\sverkh_genabstring.exe 789 100000 5" "tests\447" 447
call scripts\gen-input-via-stdout.bat "files\sverkh_genabstring.exe 234 100000 2" "tests\448" 448
call scripts\gen-input-via-stdout.bat "files\sverkh_genabstring.exe 872 100000 10" "tests\449" 449
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe" "tests\450" 450
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe bc" "tests\451" 451
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe ac" "tests\452" 452
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe sd" "tests\453" 453
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe az" "tests\454" 454
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe dk" "tests\455" 455
call scripts\gen-input-via-stdout.bat "files\sverkh2_antihash.exe el" "tests\456" 456
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe" "tests\457" 457
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe 3568" "tests\458" 458
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe 7326" "tests\459" 459
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe 2853" "tests\460" 460
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe 9427" "tests\461" 461
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring2.exe" "tests\462" 462
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring2.exe 3568" "tests\463" 463
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring2.exe 7326" "tests\464" 464
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring2.exe 2853" "tests\465" 465
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring2.exe 9427" "tests\466" 466
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe a" "tests\467" 467
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe ab" "tests\468" 468
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe abb" "tests\469" 469
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe babaaab" "tests\470" 470
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe ababababababababa" "tests\471" 471
call scripts\gen-input-via-stdout.bat "files\sverkh2_genmul.exe bbbbbabababaaabbaaba" "tests\472" 472
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe" "tests\473" 473
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 3568" "tests\474" 474
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 7326" "tests\475" 475
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 2853" "tests\476" 476
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 9427" "tests\477" 477
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 35681" "tests\478" 478
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 73261" "tests\479" 479
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 28531" "tests\480" 480
call scripts\gen-input-via-stdout.bat "files\sverkh2_rnd.exe 94271" "tests\481" 481
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbitnumbers.exe 234 100" "tests\482" 482
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbitnumbers.exe 123 1000" "tests\483" 483
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbitnumbers.exe 98984 10000" "tests\484" 484
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbitnumbers.exe 23421 50000" "tests\485" 485
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbitnumbers.exe 23487 1000000" "tests\486" 486
call scripts\gen-input-via-stdout.bat "files\sverkh2_genabstring.exe 123 1000 10" "tests\487" 487
call scripts\gen-input-via-stdout.bat "files\sverkh2_genabstring.exe 456 10000 5" "tests\488" 488
call scripts\gen-input-via-stdout.bat "files\sverkh2_genabstring.exe 789 100000 5" "tests\489" 489
call scripts\gen-input-via-stdout.bat "files\sverkh2_genabstring.exe 234 100000 2" "tests\490" 490
call scripts\gen-input-via-stdout.bat "files\sverkh2_genabstring.exe 872 100000 10" "tests\491" 491
call scripts\gen-input-via-stdout.bat "files\sverkh2_genbadstring.exe 234 1000000 50" "tests\492" 492
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 3" "tests\493" 493
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 4" "tests\494" 494
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 5" "tests\495" 495
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 6" "tests\496" 496
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 7" "tests\497" 497
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 8" "tests\498" 498
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 9" "tests\499" 499
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 10" "tests\500" 500
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 11" "tests\501" 501
call scripts\gen-input-via-stdout.bat "files\gen_pup.exe 12" "tests\502" 502
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 1234" "tests\503" 503
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 100500" "tests\504" 504
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 200500" "tests\505" 505
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 999995" "tests\506" 506
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 999996" "tests\507" 507
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 999997" "tests\508" 508
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 999998" "tests\509" 509
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 999999" "tests\510" 510
call scripts\gen-input-via-stdout.bat "files\gen_periodic.exe 1000000" "tests\511" 511
call scripts\gen-input-via-stdout.bat "files\gen_baum.exe 1000000" "tests\512" 512
call scripts\gen-input-via-stdout.bat "files\gen_paper.exe 1000000" "tests\513" 513
call scripts\gen-input-via-stdout.bat "files\gen_sf.exe 1000000" "tests\514" 514
call scripts\gen-input-via-stdout.bat "files\gen_thue.exe 1000000" "tests\515" 515
call scripts\gen-input-via-stdout.bat "files\gen_fib.exe 1000" "tests\516" 516
call scripts\gen-input-via-stdout.bat "files\gen_fib.exe 100000" "tests\517" 517
call scripts\gen-input-via-stdout.bat "files\gen_fib.exe 1000000" "tests\518" 518
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""
call scripts\gen-answer.bat tests\43 tests\43.a "tests" ""
call scripts\gen-answer.bat tests\44 tests\44.a "tests" ""
call scripts\gen-answer.bat tests\45 tests\45.a "tests" ""
call scripts\gen-answer.bat tests\46 tests\46.a "tests" ""
call scripts\gen-answer.bat tests\47 tests\47.a "tests" ""
call scripts\gen-answer.bat tests\48 tests\48.a "tests" ""
call scripts\gen-answer.bat tests\49 tests\49.a "tests" ""
call scripts\gen-answer.bat tests\50 tests\50.a "tests" ""
call scripts\gen-answer.bat tests\51 tests\51.a "tests" ""
call scripts\gen-answer.bat tests\52 tests\52.a "tests" ""
call scripts\gen-answer.bat tests\53 tests\53.a "tests" ""
call scripts\gen-answer.bat tests\54 tests\54.a "tests" ""
call scripts\gen-answer.bat tests\55 tests\55.a "tests" ""
call scripts\gen-answer.bat tests\56 tests\56.a "tests" ""
call scripts\gen-answer.bat tests\57 tests\57.a "tests" ""
call scripts\gen-answer.bat tests\58 tests\58.a "tests" ""
call scripts\gen-answer.bat tests\59 tests\59.a "tests" ""
call scripts\gen-answer.bat tests\60 tests\60.a "tests" ""
call scripts\gen-answer.bat tests\61 tests\61.a "tests" ""
call scripts\gen-answer.bat tests\62 tests\62.a "tests" ""
call scripts\gen-answer.bat tests\63 tests\63.a "tests" ""
call scripts\gen-answer.bat tests\64 tests\64.a "tests" ""
call scripts\gen-answer.bat tests\65 tests\65.a "tests" ""
call scripts\gen-answer.bat tests\66 tests\66.a "tests" ""
call scripts\gen-answer.bat tests\67 tests\67.a "tests" ""
call scripts\gen-answer.bat tests\68 tests\68.a "tests" ""
call scripts\gen-answer.bat tests\69 tests\69.a "tests" ""
call scripts\gen-answer.bat tests\70 tests\70.a "tests" ""
call scripts\gen-answer.bat tests\71 tests\71.a "tests" ""
call scripts\gen-answer.bat tests\72 tests\72.a "tests" ""
call scripts\gen-answer.bat tests\73 tests\73.a "tests" ""
call scripts\gen-answer.bat tests\74 tests\74.a "tests" ""
call scripts\gen-answer.bat tests\75 tests\75.a "tests" ""
call scripts\gen-answer.bat tests\76 tests\76.a "tests" ""
call scripts\gen-answer.bat tests\77 tests\77.a "tests" ""
call scripts\gen-answer.bat tests\78 tests\78.a "tests" ""
call scripts\gen-answer.bat tests\79 tests\79.a "tests" ""
call scripts\gen-answer.bat tests\80 tests\80.a "tests" ""
call scripts\gen-answer.bat tests\81 tests\81.a "tests" ""
call scripts\gen-answer.bat tests\82 tests\82.a "tests" ""
call scripts\gen-answer.bat tests\83 tests\83.a "tests" ""
call scripts\gen-answer.bat tests\84 tests\84.a "tests" ""
call scripts\gen-answer.bat tests\85 tests\85.a "tests" ""
call scripts\gen-answer.bat tests\86 tests\86.a "tests" ""
call scripts\gen-answer.bat tests\87 tests\87.a "tests" ""
call scripts\gen-answer.bat tests\88 tests\88.a "tests" ""
call scripts\gen-answer.bat tests\89 tests\89.a "tests" ""
call scripts\gen-answer.bat tests\90 tests\90.a "tests" ""
call scripts\gen-answer.bat tests\91 tests\91.a "tests" ""
call scripts\gen-answer.bat tests\92 tests\92.a "tests" ""
call scripts\gen-answer.bat tests\93 tests\93.a "tests" ""
call scripts\gen-answer.bat tests\94 tests\94.a "tests" ""
call scripts\gen-answer.bat tests\95 tests\95.a "tests" ""
call scripts\gen-answer.bat tests\96 tests\96.a "tests" ""
call scripts\gen-answer.bat tests\97 tests\97.a "tests" ""
call scripts\gen-answer.bat tests\98 tests\98.a "tests" ""
call scripts\gen-answer.bat tests\99 tests\99.a "tests" ""
call scripts\gen-answer.bat tests\100 tests\100.a "tests" ""
call scripts\gen-answer.bat tests\101 tests\101.a "tests" ""
call scripts\gen-answer.bat tests\102 tests\102.a "tests" ""
call scripts\gen-answer.bat tests\103 tests\103.a "tests" ""
call scripts\gen-answer.bat tests\104 tests\104.a "tests" ""
call scripts\gen-answer.bat tests\105 tests\105.a "tests" ""
call scripts\gen-answer.bat tests\106 tests\106.a "tests" ""
call scripts\gen-answer.bat tests\107 tests\107.a "tests" ""
call scripts\gen-answer.bat tests\108 tests\108.a "tests" ""
call scripts\gen-answer.bat tests\109 tests\109.a "tests" ""
call scripts\gen-answer.bat tests\110 tests\110.a "tests" ""
call scripts\gen-answer.bat tests\111 tests\111.a "tests" ""
call scripts\gen-answer.bat tests\112 tests\112.a "tests" ""
call scripts\gen-answer.bat tests\113 tests\113.a "tests" ""
call scripts\gen-answer.bat tests\114 tests\114.a "tests" ""
call scripts\gen-answer.bat tests\115 tests\115.a "tests" ""
call scripts\gen-answer.bat tests\116 tests\116.a "tests" ""
call scripts\gen-answer.bat tests\117 tests\117.a "tests" ""
call scripts\gen-answer.bat tests\118 tests\118.a "tests" ""
call scripts\gen-answer.bat tests\119 tests\119.a "tests" ""
call scripts\gen-answer.bat tests\120 tests\120.a "tests" ""
call scripts\gen-answer.bat tests\121 tests\121.a "tests" ""
call scripts\gen-answer.bat tests\122 tests\122.a "tests" ""
call scripts\gen-answer.bat tests\123 tests\123.a "tests" ""
call scripts\gen-answer.bat tests\124 tests\124.a "tests" ""
call scripts\gen-answer.bat tests\125 tests\125.a "tests" ""
call scripts\gen-answer.bat tests\126 tests\126.a "tests" ""
call scripts\gen-answer.bat tests\127 tests\127.a "tests" ""
call scripts\gen-answer.bat tests\128 tests\128.a "tests" ""
call scripts\gen-answer.bat tests\129 tests\129.a "tests" ""
call scripts\gen-answer.bat tests\130 tests\130.a "tests" ""
call scripts\gen-answer.bat tests\131 tests\131.a "tests" ""
call scripts\gen-answer.bat tests\132 tests\132.a "tests" ""
call scripts\gen-answer.bat tests\133 tests\133.a "tests" ""
call scripts\gen-answer.bat tests\134 tests\134.a "tests" ""
call scripts\gen-answer.bat tests\135 tests\135.a "tests" ""
call scripts\gen-answer.bat tests\136 tests\136.a "tests" ""
call scripts\gen-answer.bat tests\137 tests\137.a "tests" ""
call scripts\gen-answer.bat tests\138 tests\138.a "tests" ""
call scripts\gen-answer.bat tests\139 tests\139.a "tests" ""
call scripts\gen-answer.bat tests\140 tests\140.a "tests" ""
call scripts\gen-answer.bat tests\141 tests\141.a "tests" ""
call scripts\gen-answer.bat tests\142 tests\142.a "tests" ""
call scripts\gen-answer.bat tests\143 tests\143.a "tests" ""
call scripts\gen-answer.bat tests\144 tests\144.a "tests" ""
call scripts\gen-answer.bat tests\145 tests\145.a "tests" ""
call scripts\gen-answer.bat tests\146 tests\146.a "tests" ""
call scripts\gen-answer.bat tests\147 tests\147.a "tests" ""
call scripts\gen-answer.bat tests\148 tests\148.a "tests" ""
call scripts\gen-answer.bat tests\149 tests\149.a "tests" ""
call scripts\gen-answer.bat tests\150 tests\150.a "tests" ""
call scripts\gen-answer.bat tests\151 tests\151.a "tests" ""
call scripts\gen-answer.bat tests\152 tests\152.a "tests" ""
call scripts\gen-answer.bat tests\153 tests\153.a "tests" ""
call scripts\gen-answer.bat tests\154 tests\154.a "tests" ""
call scripts\gen-answer.bat tests\155 tests\155.a "tests" ""
call scripts\gen-answer.bat tests\156 tests\156.a "tests" ""
call scripts\gen-answer.bat tests\157 tests\157.a "tests" ""
call scripts\gen-answer.bat tests\158 tests\158.a "tests" ""
call scripts\gen-answer.bat tests\159 tests\159.a "tests" ""
call scripts\gen-answer.bat tests\160 tests\160.a "tests" ""
call scripts\gen-answer.bat tests\161 tests\161.a "tests" ""
call scripts\gen-answer.bat tests\162 tests\162.a "tests" ""
call scripts\gen-answer.bat tests\163 tests\163.a "tests" ""
call scripts\gen-answer.bat tests\164 tests\164.a "tests" ""
call scripts\gen-answer.bat tests\165 tests\165.a "tests" ""
call scripts\gen-answer.bat tests\166 tests\166.a "tests" ""
call scripts\gen-answer.bat tests\167 tests\167.a "tests" ""
call scripts\gen-answer.bat tests\168 tests\168.a "tests" ""
call scripts\gen-answer.bat tests\169 tests\169.a "tests" ""
call scripts\gen-answer.bat tests\170 tests\170.a "tests" ""
call scripts\gen-answer.bat tests\171 tests\171.a "tests" ""
call scripts\gen-answer.bat tests\172 tests\172.a "tests" ""
call scripts\gen-answer.bat tests\173 tests\173.a "tests" ""
call scripts\gen-answer.bat tests\174 tests\174.a "tests" ""
call scripts\gen-answer.bat tests\175 tests\175.a "tests" ""
call scripts\gen-answer.bat tests\176 tests\176.a "tests" ""
call scripts\gen-answer.bat tests\177 tests\177.a "tests" ""
call scripts\gen-answer.bat tests\178 tests\178.a "tests" ""
call scripts\gen-answer.bat tests\179 tests\179.a "tests" ""
call scripts\gen-answer.bat tests\180 tests\180.a "tests" ""
call scripts\gen-answer.bat tests\181 tests\181.a "tests" ""
call scripts\gen-answer.bat tests\182 tests\182.a "tests" ""
call scripts\gen-answer.bat tests\183 tests\183.a "tests" ""
call scripts\gen-answer.bat tests\184 tests\184.a "tests" ""
call scripts\gen-answer.bat tests\185 tests\185.a "tests" ""
call scripts\gen-answer.bat tests\186 tests\186.a "tests" ""
call scripts\gen-answer.bat tests\187 tests\187.a "tests" ""
call scripts\gen-answer.bat tests\188 tests\188.a "tests" ""
call scripts\gen-answer.bat tests\189 tests\189.a "tests" ""
call scripts\gen-answer.bat tests\190 tests\190.a "tests" ""
call scripts\gen-answer.bat tests\191 tests\191.a "tests" ""
call scripts\gen-answer.bat tests\192 tests\192.a "tests" ""
call scripts\gen-answer.bat tests\193 tests\193.a "tests" ""
call scripts\gen-answer.bat tests\194 tests\194.a "tests" ""
call scripts\gen-answer.bat tests\195 tests\195.a "tests" ""
call scripts\gen-answer.bat tests\196 tests\196.a "tests" ""
call scripts\gen-answer.bat tests\197 tests\197.a "tests" ""
call scripts\gen-answer.bat tests\198 tests\198.a "tests" ""
call scripts\gen-answer.bat tests\199 tests\199.a "tests" ""
call scripts\gen-answer.bat tests\200 tests\200.a "tests" ""
call scripts\gen-answer.bat tests\201 tests\201.a "tests" ""
call scripts\gen-answer.bat tests\202 tests\202.a "tests" ""
call scripts\gen-answer.bat tests\203 tests\203.a "tests" ""
call scripts\gen-answer.bat tests\204 tests\204.a "tests" ""
call scripts\gen-answer.bat tests\205 tests\205.a "tests" ""
call scripts\gen-answer.bat tests\206 tests\206.a "tests" ""
call scripts\gen-answer.bat tests\207 tests\207.a "tests" ""
call scripts\gen-answer.bat tests\208 tests\208.a "tests" ""
call scripts\gen-answer.bat tests\209 tests\209.a "tests" ""
call scripts\gen-answer.bat tests\210 tests\210.a "tests" ""
call scripts\gen-answer.bat tests\211 tests\211.a "tests" ""
call scripts\gen-answer.bat tests\212 tests\212.a "tests" ""
call scripts\gen-answer.bat tests\213 tests\213.a "tests" ""
call scripts\gen-answer.bat tests\214 tests\214.a "tests" ""
call scripts\gen-answer.bat tests\215 tests\215.a "tests" ""
call scripts\gen-answer.bat tests\216 tests\216.a "tests" ""
call scripts\gen-answer.bat tests\217 tests\217.a "tests" ""
call scripts\gen-answer.bat tests\218 tests\218.a "tests" ""
call scripts\gen-answer.bat tests\219 tests\219.a "tests" ""
call scripts\gen-answer.bat tests\220 tests\220.a "tests" ""
call scripts\gen-answer.bat tests\221 tests\221.a "tests" ""
call scripts\gen-answer.bat tests\222 tests\222.a "tests" ""
call scripts\gen-answer.bat tests\223 tests\223.a "tests" ""
call scripts\gen-answer.bat tests\224 tests\224.a "tests" ""
call scripts\gen-answer.bat tests\225 tests\225.a "tests" ""
call scripts\gen-answer.bat tests\226 tests\226.a "tests" ""
call scripts\gen-answer.bat tests\227 tests\227.a "tests" ""
call scripts\gen-answer.bat tests\228 tests\228.a "tests" ""
call scripts\gen-answer.bat tests\229 tests\229.a "tests" ""
call scripts\gen-answer.bat tests\230 tests\230.a "tests" ""
call scripts\gen-answer.bat tests\231 tests\231.a "tests" ""
call scripts\gen-answer.bat tests\232 tests\232.a "tests" ""
call scripts\gen-answer.bat tests\233 tests\233.a "tests" ""
call scripts\gen-answer.bat tests\234 tests\234.a "tests" ""
call scripts\gen-answer.bat tests\235 tests\235.a "tests" ""
call scripts\gen-answer.bat tests\236 tests\236.a "tests" ""
call scripts\gen-answer.bat tests\237 tests\237.a "tests" ""
call scripts\gen-answer.bat tests\238 tests\238.a "tests" ""
call scripts\gen-answer.bat tests\239 tests\239.a "tests" ""
call scripts\gen-answer.bat tests\240 tests\240.a "tests" ""
call scripts\gen-answer.bat tests\241 tests\241.a "tests" ""
call scripts\gen-answer.bat tests\242 tests\242.a "tests" ""
call scripts\gen-answer.bat tests\243 tests\243.a "tests" ""
call scripts\gen-answer.bat tests\244 tests\244.a "tests" ""
call scripts\gen-answer.bat tests\245 tests\245.a "tests" ""
call scripts\gen-answer.bat tests\246 tests\246.a "tests" ""
call scripts\gen-answer.bat tests\247 tests\247.a "tests" ""
call scripts\gen-answer.bat tests\248 tests\248.a "tests" ""
call scripts\gen-answer.bat tests\249 tests\249.a "tests" ""
call scripts\gen-answer.bat tests\250 tests\250.a "tests" ""
call scripts\gen-answer.bat tests\251 tests\251.a "tests" ""
call scripts\gen-answer.bat tests\252 tests\252.a "tests" ""
call scripts\gen-answer.bat tests\253 tests\253.a "tests" ""
call scripts\gen-answer.bat tests\254 tests\254.a "tests" ""
call scripts\gen-answer.bat tests\255 tests\255.a "tests" ""
call scripts\gen-answer.bat tests\256 tests\256.a "tests" ""
call scripts\gen-answer.bat tests\257 tests\257.a "tests" ""
call scripts\gen-answer.bat tests\258 tests\258.a "tests" ""
call scripts\gen-answer.bat tests\259 tests\259.a "tests" ""
call scripts\gen-answer.bat tests\260 tests\260.a "tests" ""
call scripts\gen-answer.bat tests\261 tests\261.a "tests" ""
call scripts\gen-answer.bat tests\262 tests\262.a "tests" ""
call scripts\gen-answer.bat tests\263 tests\263.a "tests" ""
call scripts\gen-answer.bat tests\264 tests\264.a "tests" ""
call scripts\gen-answer.bat tests\265 tests\265.a "tests" ""
call scripts\gen-answer.bat tests\266 tests\266.a "tests" ""
call scripts\gen-answer.bat tests\267 tests\267.a "tests" ""
call scripts\gen-answer.bat tests\268 tests\268.a "tests" ""
call scripts\gen-answer.bat tests\269 tests\269.a "tests" ""
call scripts\gen-answer.bat tests\270 tests\270.a "tests" ""
call scripts\gen-answer.bat tests\271 tests\271.a "tests" ""
call scripts\gen-answer.bat tests\272 tests\272.a "tests" ""
call scripts\gen-answer.bat tests\273 tests\273.a "tests" ""
call scripts\gen-answer.bat tests\274 tests\274.a "tests" ""
call scripts\gen-answer.bat tests\275 tests\275.a "tests" ""
call scripts\gen-answer.bat tests\276 tests\276.a "tests" ""
call scripts\gen-answer.bat tests\277 tests\277.a "tests" ""
call scripts\gen-answer.bat tests\278 tests\278.a "tests" ""
call scripts\gen-answer.bat tests\279 tests\279.a "tests" ""
call scripts\gen-answer.bat tests\280 tests\280.a "tests" ""
call scripts\gen-answer.bat tests\281 tests\281.a "tests" ""
call scripts\gen-answer.bat tests\282 tests\282.a "tests" ""
call scripts\gen-answer.bat tests\283 tests\283.a "tests" ""
call scripts\gen-answer.bat tests\284 tests\284.a "tests" ""
call scripts\gen-answer.bat tests\285 tests\285.a "tests" ""
call scripts\gen-answer.bat tests\286 tests\286.a "tests" ""
call scripts\gen-answer.bat tests\287 tests\287.a "tests" ""
call scripts\gen-answer.bat tests\288 tests\288.a "tests" ""
call scripts\gen-answer.bat tests\289 tests\289.a "tests" ""
call scripts\gen-answer.bat tests\290 tests\290.a "tests" ""
call scripts\gen-answer.bat tests\291 tests\291.a "tests" ""
call scripts\gen-answer.bat tests\292 tests\292.a "tests" ""
call scripts\gen-answer.bat tests\293 tests\293.a "tests" ""
call scripts\gen-answer.bat tests\294 tests\294.a "tests" ""
call scripts\gen-answer.bat tests\295 tests\295.a "tests" ""
call scripts\gen-answer.bat tests\296 tests\296.a "tests" ""
call scripts\gen-answer.bat tests\297 tests\297.a "tests" ""
call scripts\gen-answer.bat tests\298 tests\298.a "tests" ""
call scripts\gen-answer.bat tests\299 tests\299.a "tests" ""
call scripts\gen-answer.bat tests\300 tests\300.a "tests" ""
call scripts\gen-answer.bat tests\301 tests\301.a "tests" ""
call scripts\gen-answer.bat tests\302 tests\302.a "tests" ""
call scripts\gen-answer.bat tests\303 tests\303.a "tests" ""
call scripts\gen-answer.bat tests\304 tests\304.a "tests" ""
call scripts\gen-answer.bat tests\305 tests\305.a "tests" ""
call scripts\gen-answer.bat tests\306 tests\306.a "tests" ""
call scripts\gen-answer.bat tests\307 tests\307.a "tests" ""
call scripts\gen-answer.bat tests\308 tests\308.a "tests" ""
call scripts\gen-answer.bat tests\309 tests\309.a "tests" ""
call scripts\gen-answer.bat tests\310 tests\310.a "tests" ""
call scripts\gen-answer.bat tests\311 tests\311.a "tests" ""
call scripts\gen-answer.bat tests\312 tests\312.a "tests" ""
call scripts\gen-answer.bat tests\313 tests\313.a "tests" ""
call scripts\gen-answer.bat tests\314 tests\314.a "tests" ""
call scripts\gen-answer.bat tests\315 tests\315.a "tests" ""
call scripts\gen-answer.bat tests\316 tests\316.a "tests" ""
call scripts\gen-answer.bat tests\317 tests\317.a "tests" ""
call scripts\gen-answer.bat tests\318 tests\318.a "tests" ""
call scripts\gen-answer.bat tests\319 tests\319.a "tests" ""
call scripts\gen-answer.bat tests\320 tests\320.a "tests" ""
call scripts\gen-answer.bat tests\321 tests\321.a "tests" ""
call scripts\gen-answer.bat tests\322 tests\322.a "tests" ""
call scripts\gen-answer.bat tests\323 tests\323.a "tests" ""
call scripts\gen-answer.bat tests\324 tests\324.a "tests" ""
call scripts\gen-answer.bat tests\325 tests\325.a "tests" ""
call scripts\gen-answer.bat tests\326 tests\326.a "tests" ""
call scripts\gen-answer.bat tests\327 tests\327.a "tests" ""
call scripts\gen-answer.bat tests\328 tests\328.a "tests" ""
call scripts\gen-answer.bat tests\329 tests\329.a "tests" ""
call scripts\gen-answer.bat tests\330 tests\330.a "tests" ""
call scripts\gen-answer.bat tests\331 tests\331.a "tests" ""
call scripts\gen-answer.bat tests\332 tests\332.a "tests" ""
call scripts\gen-answer.bat tests\333 tests\333.a "tests" ""
call scripts\gen-answer.bat tests\334 tests\334.a "tests" ""
call scripts\gen-answer.bat tests\335 tests\335.a "tests" ""
call scripts\gen-answer.bat tests\336 tests\336.a "tests" ""
call scripts\gen-answer.bat tests\337 tests\337.a "tests" ""
call scripts\gen-answer.bat tests\338 tests\338.a "tests" ""
call scripts\gen-answer.bat tests\339 tests\339.a "tests" ""
call scripts\gen-answer.bat tests\340 tests\340.a "tests" ""
call scripts\gen-answer.bat tests\341 tests\341.a "tests" ""
call scripts\gen-answer.bat tests\342 tests\342.a "tests" ""
call scripts\gen-answer.bat tests\343 tests\343.a "tests" ""
call scripts\gen-answer.bat tests\344 tests\344.a "tests" ""
call scripts\gen-answer.bat tests\345 tests\345.a "tests" ""
call scripts\gen-answer.bat tests\346 tests\346.a "tests" ""
call scripts\gen-answer.bat tests\347 tests\347.a "tests" ""
call scripts\gen-answer.bat tests\348 tests\348.a "tests" ""
call scripts\gen-answer.bat tests\349 tests\349.a "tests" ""
call scripts\gen-answer.bat tests\350 tests\350.a "tests" ""
call scripts\gen-answer.bat tests\351 tests\351.a "tests" ""
call scripts\gen-answer.bat tests\352 tests\352.a "tests" ""
call scripts\gen-answer.bat tests\353 tests\353.a "tests" ""
call scripts\gen-answer.bat tests\354 tests\354.a "tests" ""
call scripts\gen-answer.bat tests\355 tests\355.a "tests" ""
call scripts\gen-answer.bat tests\356 tests\356.a "tests" ""
call scripts\gen-answer.bat tests\357 tests\357.a "tests" ""
call scripts\gen-answer.bat tests\358 tests\358.a "tests" ""
call scripts\gen-answer.bat tests\359 tests\359.a "tests" ""
call scripts\gen-answer.bat tests\360 tests\360.a "tests" ""
call scripts\gen-answer.bat tests\361 tests\361.a "tests" ""
call scripts\gen-answer.bat tests\362 tests\362.a "tests" ""
call scripts\gen-answer.bat tests\363 tests\363.a "tests" ""
call scripts\gen-answer.bat tests\364 tests\364.a "tests" ""
call scripts\gen-answer.bat tests\365 tests\365.a "tests" ""
call scripts\gen-answer.bat tests\366 tests\366.a "tests" ""
call scripts\gen-answer.bat tests\367 tests\367.a "tests" ""
call scripts\gen-answer.bat tests\368 tests\368.a "tests" ""
call scripts\gen-answer.bat tests\369 tests\369.a "tests" ""
call scripts\gen-answer.bat tests\370 tests\370.a "tests" ""
call scripts\gen-answer.bat tests\371 tests\371.a "tests" ""
call scripts\gen-answer.bat tests\372 tests\372.a "tests" ""
call scripts\gen-answer.bat tests\373 tests\373.a "tests" ""
call scripts\gen-answer.bat tests\374 tests\374.a "tests" ""
call scripts\gen-answer.bat tests\375 tests\375.a "tests" ""
call scripts\gen-answer.bat tests\376 tests\376.a "tests" ""
call scripts\gen-answer.bat tests\377 tests\377.a "tests" ""
call scripts\gen-answer.bat tests\378 tests\378.a "tests" ""
call scripts\gen-answer.bat tests\379 tests\379.a "tests" ""
call scripts\gen-answer.bat tests\380 tests\380.a "tests" ""
call scripts\gen-answer.bat tests\381 tests\381.a "tests" ""
call scripts\gen-answer.bat tests\382 tests\382.a "tests" ""
call scripts\gen-answer.bat tests\383 tests\383.a "tests" ""
call scripts\gen-answer.bat tests\384 tests\384.a "tests" ""
call scripts\gen-answer.bat tests\385 tests\385.a "tests" ""
call scripts\gen-answer.bat tests\386 tests\386.a "tests" ""
call scripts\gen-answer.bat tests\387 tests\387.a "tests" ""
call scripts\gen-answer.bat tests\388 tests\388.a "tests" ""
call scripts\gen-answer.bat tests\389 tests\389.a "tests" ""
call scripts\gen-answer.bat tests\390 tests\390.a "tests" ""
call scripts\gen-answer.bat tests\391 tests\391.a "tests" ""
call scripts\gen-answer.bat tests\392 tests\392.a "tests" ""
call scripts\gen-answer.bat tests\393 tests\393.a "tests" ""
call scripts\gen-answer.bat tests\394 tests\394.a "tests" ""
call scripts\gen-answer.bat tests\395 tests\395.a "tests" ""
call scripts\gen-answer.bat tests\396 tests\396.a "tests" ""
call scripts\gen-answer.bat tests\397 tests\397.a "tests" ""
call scripts\gen-answer.bat tests\398 tests\398.a "tests" ""
call scripts\gen-answer.bat tests\399 tests\399.a "tests" ""
call scripts\gen-answer.bat tests\400 tests\400.a "tests" ""
call scripts\gen-answer.bat tests\401 tests\401.a "tests" ""
call scripts\gen-answer.bat tests\402 tests\402.a "tests" ""
call scripts\gen-answer.bat tests\403 tests\403.a "tests" ""
call scripts\gen-answer.bat tests\404 tests\404.a "tests" ""
call scripts\gen-answer.bat tests\405 tests\405.a "tests" ""
call scripts\gen-answer.bat tests\406 tests\406.a "tests" ""
call scripts\gen-answer.bat tests\407 tests\407.a "tests" ""
call scripts\gen-answer.bat tests\408 tests\408.a "tests" ""
call scripts\gen-answer.bat tests\409 tests\409.a "tests" ""
call scripts\gen-answer.bat tests\410 tests\410.a "tests" ""
call scripts\gen-answer.bat tests\411 tests\411.a "tests" ""
call scripts\gen-answer.bat tests\412 tests\412.a "tests" ""
call scripts\gen-answer.bat tests\413 tests\413.a "tests" ""
call scripts\gen-answer.bat tests\414 tests\414.a "tests" ""
call scripts\gen-answer.bat tests\415 tests\415.a "tests" ""
call scripts\gen-answer.bat tests\416 tests\416.a "tests" ""
call scripts\gen-answer.bat tests\417 tests\417.a "tests" ""
call scripts\gen-answer.bat tests\418 tests\418.a "tests" ""
call scripts\gen-answer.bat tests\419 tests\419.a "tests" ""
call scripts\gen-answer.bat tests\420 tests\420.a "tests" ""
call scripts\gen-answer.bat tests\421 tests\421.a "tests" ""
call scripts\gen-answer.bat tests\422 tests\422.a "tests" ""
call scripts\gen-answer.bat tests\423 tests\423.a "tests" ""
call scripts\gen-answer.bat tests\424 tests\424.a "tests" ""
call scripts\gen-answer.bat tests\425 tests\425.a "tests" ""
call scripts\gen-answer.bat tests\426 tests\426.a "tests" ""
call scripts\gen-answer.bat tests\427 tests\427.a "tests" ""
call scripts\gen-answer.bat tests\428 tests\428.a "tests" ""
call scripts\gen-answer.bat tests\429 tests\429.a "tests" ""
call scripts\gen-answer.bat tests\430 tests\430.a "tests" ""
call scripts\gen-answer.bat tests\431 tests\431.a "tests" ""
call scripts\gen-answer.bat tests\432 tests\432.a "tests" ""
call scripts\gen-answer.bat tests\433 tests\433.a "tests" ""
call scripts\gen-answer.bat tests\434 tests\434.a "tests" ""
call scripts\gen-answer.bat tests\435 tests\435.a "tests" ""
call scripts\gen-answer.bat tests\436 tests\436.a "tests" ""
call scripts\gen-answer.bat tests\437 tests\437.a "tests" ""
call scripts\gen-answer.bat tests\438 tests\438.a "tests" ""
call scripts\gen-answer.bat tests\439 tests\439.a "tests" ""
call scripts\gen-answer.bat tests\440 tests\440.a "tests" ""
call scripts\gen-answer.bat tests\441 tests\441.a "tests" ""
call scripts\gen-answer.bat tests\442 tests\442.a "tests" ""
call scripts\gen-answer.bat tests\443 tests\443.a "tests" ""
call scripts\gen-answer.bat tests\444 tests\444.a "tests" ""
call scripts\gen-answer.bat tests\445 tests\445.a "tests" ""
call scripts\gen-answer.bat tests\446 tests\446.a "tests" ""
call scripts\gen-answer.bat tests\447 tests\447.a "tests" ""
call scripts\gen-answer.bat tests\448 tests\448.a "tests" ""
call scripts\gen-answer.bat tests\449 tests\449.a "tests" ""
call scripts\gen-answer.bat tests\450 tests\450.a "tests" ""
call scripts\gen-answer.bat tests\451 tests\451.a "tests" ""
call scripts\gen-answer.bat tests\452 tests\452.a "tests" ""
call scripts\gen-answer.bat tests\453 tests\453.a "tests" ""
call scripts\gen-answer.bat tests\454 tests\454.a "tests" ""
call scripts\gen-answer.bat tests\455 tests\455.a "tests" ""
call scripts\gen-answer.bat tests\456 tests\456.a "tests" ""
call scripts\gen-answer.bat tests\457 tests\457.a "tests" ""
call scripts\gen-answer.bat tests\458 tests\458.a "tests" ""
call scripts\gen-answer.bat tests\459 tests\459.a "tests" ""
call scripts\gen-answer.bat tests\460 tests\460.a "tests" ""
call scripts\gen-answer.bat tests\461 tests\461.a "tests" ""
call scripts\gen-answer.bat tests\462 tests\462.a "tests" ""
call scripts\gen-answer.bat tests\463 tests\463.a "tests" ""
call scripts\gen-answer.bat tests\464 tests\464.a "tests" ""
call scripts\gen-answer.bat tests\465 tests\465.a "tests" ""
call scripts\gen-answer.bat tests\466 tests\466.a "tests" ""
call scripts\gen-answer.bat tests\467 tests\467.a "tests" ""
call scripts\gen-answer.bat tests\468 tests\468.a "tests" ""
call scripts\gen-answer.bat tests\469 tests\469.a "tests" ""
call scripts\gen-answer.bat tests\470 tests\470.a "tests" ""
call scripts\gen-answer.bat tests\471 tests\471.a "tests" ""
call scripts\gen-answer.bat tests\472 tests\472.a "tests" ""
call scripts\gen-answer.bat tests\473 tests\473.a "tests" ""
call scripts\gen-answer.bat tests\474 tests\474.a "tests" ""
call scripts\gen-answer.bat tests\475 tests\475.a "tests" ""
call scripts\gen-answer.bat tests\476 tests\476.a "tests" ""
call scripts\gen-answer.bat tests\477 tests\477.a "tests" ""
call scripts\gen-answer.bat tests\478 tests\478.a "tests" ""
call scripts\gen-answer.bat tests\479 tests\479.a "tests" ""
call scripts\gen-answer.bat tests\480 tests\480.a "tests" ""
call scripts\gen-answer.bat tests\481 tests\481.a "tests" ""
call scripts\gen-answer.bat tests\482 tests\482.a "tests" ""
call scripts\gen-answer.bat tests\483 tests\483.a "tests" ""
call scripts\gen-answer.bat tests\484 tests\484.a "tests" ""
call scripts\gen-answer.bat tests\485 tests\485.a "tests" ""
call scripts\gen-answer.bat tests\486 tests\486.a "tests" ""
call scripts\gen-answer.bat tests\487 tests\487.a "tests" ""
call scripts\gen-answer.bat tests\488 tests\488.a "tests" ""
call scripts\gen-answer.bat tests\489 tests\489.a "tests" ""
call scripts\gen-answer.bat tests\490 tests\490.a "tests" ""
call scripts\gen-answer.bat tests\491 tests\491.a "tests" ""
call scripts\gen-answer.bat tests\492 tests\492.a "tests" ""
call scripts\gen-answer.bat tests\493 tests\493.a "tests" ""
call scripts\gen-answer.bat tests\494 tests\494.a "tests" ""
call scripts\gen-answer.bat tests\495 tests\495.a "tests" ""
call scripts\gen-answer.bat tests\496 tests\496.a "tests" ""
call scripts\gen-answer.bat tests\497 tests\497.a "tests" ""
call scripts\gen-answer.bat tests\498 tests\498.a "tests" ""
call scripts\gen-answer.bat tests\499 tests\499.a "tests" ""
call scripts\gen-answer.bat tests\500 tests\500.a "tests" ""
call scripts\gen-answer.bat tests\501 tests\501.a "tests" ""
call scripts\gen-answer.bat tests\502 tests\502.a "tests" ""
call scripts\gen-answer.bat tests\503 tests\503.a "tests" ""
call scripts\gen-answer.bat tests\504 tests\504.a "tests" ""
call scripts\gen-answer.bat tests\505 tests\505.a "tests" ""
call scripts\gen-answer.bat tests\506 tests\506.a "tests" ""
call scripts\gen-answer.bat tests\507 tests\507.a "tests" ""
call scripts\gen-answer.bat tests\508 tests\508.a "tests" ""
call scripts\gen-answer.bat tests\509 tests\509.a "tests" ""
call scripts\gen-answer.bat tests\510 tests\510.a "tests" ""
call scripts\gen-answer.bat tests\511 tests\511.a "tests" ""
call scripts\gen-answer.bat tests\512 tests\512.a "tests" ""
call scripts\gen-answer.bat tests\513 tests\513.a "tests" ""
call scripts\gen-answer.bat tests\514 tests\514.a "tests" ""
call scripts\gen-answer.bat tests\515 tests\515.a "tests" ""
call scripts\gen-answer.bat tests\516 tests\516.a "tests" ""
call scripts\gen-answer.bat tests\517 tests\517.a "tests" ""
call scripts\gen-answer.bat tests\518 tests\518.a "tests" ""
call scripts\gen-answer.bat tests\519 tests\519.a "tests" ""

