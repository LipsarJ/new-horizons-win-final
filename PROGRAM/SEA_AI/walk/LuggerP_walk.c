int LuggerP_walk_count;
float LuggerP_walk_verts[156];
int LuggerP_walk_types[52];
int LuggerP_walk_graph[64];

void LuggerP_walk_init()
{
        LuggerP_walk_count = 52;

        LuggerP_walk_verts[0] = -0.011811;
        LuggerP_walk_verts[1] = 3.499896;
        LuggerP_walk_verts[2] = -7.438014;
        LuggerP_walk_verts[3] = -1.454077;
        LuggerP_walk_verts[4] = 3.507397;
        LuggerP_walk_verts[5] = -6.475904;
        LuggerP_walk_verts[6] = -1.440961;
        LuggerP_walk_verts[7] = 3.689901;
        LuggerP_walk_verts[8] = -8.080803;
        LuggerP_walk_verts[9] = 1.298242;
        LuggerP_walk_verts[10] = 3.582399;
        LuggerP_walk_verts[11] = -8.376066;
        LuggerP_walk_verts[12] = 0.804694;
        LuggerP_walk_verts[13] = 3.762403;
        LuggerP_walk_verts[14] = -9.226589;
        LuggerP_walk_verts[15] = 0.566972;
        LuggerP_walk_verts[16] = 3.342394;
        LuggerP_walk_verts[17] = -5.748665;
        LuggerP_walk_verts[18] = 0.506582;
        LuggerP_walk_verts[19] = 1.962362;
        LuggerP_walk_verts[20] = -5.093957;
        LuggerP_walk_verts[21] = -0.38056;
        LuggerP_walk_verts[22] = 2.067364;
        LuggerP_walk_verts[23] = -4.806719;
        LuggerP_walk_verts[24] = -1.144417;
        LuggerP_walk_verts[25] = 2.057364;
        LuggerP_walk_verts[26] = -4.795048;
        LuggerP_walk_verts[27] = -1.323466;
        LuggerP_walk_verts[28] = 1.742356;
        LuggerP_walk_verts[29] = -2.286736;
        LuggerP_walk_verts[30] = -1.307462;
        LuggerP_walk_verts[31] = 1.88236;
        LuggerP_walk_verts[32] = 0.405247;
        LuggerP_walk_verts[33] = -1.187919;
        LuggerP_walk_verts[34] = 1.969862;
        LuggerP_walk_verts[35] = 3.057786;
        LuggerP_walk_verts[36] = -0.896803;
        LuggerP_walk_verts[37] = 1.754857;
        LuggerP_walk_verts[38] = -2.197669;
        LuggerP_walk_verts[39] = -0.762222;
        LuggerP_walk_verts[40] = 1.717355;
        LuggerP_walk_verts[41] = 0.381644;
        LuggerP_walk_verts[42] = 0.952699;
        LuggerP_walk_verts[43] = 1.759857;
        LuggerP_walk_verts[44] = 0.433442;
        LuggerP_walk_verts[45] = 0.891825;
        LuggerP_walk_verts[46] = 1.704855;
        LuggerP_walk_verts[47] = -2.166752;
        LuggerP_walk_verts[48] = -0.643858;
        LuggerP_walk_verts[49] = 1.89736;
        LuggerP_walk_verts[50] = 3.128075;
        LuggerP_walk_verts[51] = 1.286842;
        LuggerP_walk_verts[52] = 1.754857;
        LuggerP_walk_verts[53] = 0.538627;
        LuggerP_walk_verts[54] = 1.140548;
        LuggerP_walk_verts[55] = 1.814858;
        LuggerP_walk_verts[56] = 3.1169;
        LuggerP_walk_verts[57] = 1.204954;
        LuggerP_walk_verts[58] = 1.902361;
        LuggerP_walk_verts[59] = -2.069527;
        LuggerP_walk_verts[60] = 1.197629;
        LuggerP_walk_verts[61] = 2.087365;
        LuggerP_walk_verts[62] = -4.844374;
        LuggerP_walk_verts[63] = 0.520591;
        LuggerP_walk_verts[64] = 1.752357;
        LuggerP_walk_verts[65] = 3.141162;
        LuggerP_walk_verts[66] = -1.516338;
        LuggerP_walk_verts[67] = 1.599854;
        LuggerP_walk_verts[68] = 4.128622;
        LuggerP_walk_verts[69] = 1.677759;
        LuggerP_walk_verts[70] = 1.687356;
        LuggerP_walk_verts[71] = 4.230223;
        LuggerP_walk_verts[72] = 1.520522;
        LuggerP_walk_verts[73] = 2.259868;
        LuggerP_walk_verts[74] = 4.63975;
        LuggerP_walk_verts[75] = -1.56825;
        LuggerP_walk_verts[76] = 2.344872;
        LuggerP_walk_verts[77] = 4.596295;
        LuggerP_walk_verts[78] = 1.179347;
        LuggerP_walk_verts[79] = 2.379871;
        LuggerP_walk_verts[80] = 5.254359;
        LuggerP_walk_verts[81] = -1.105379;
        LuggerP_walk_verts[82] = 2.26987;
        LuggerP_walk_verts[83] = 5.386126;
        LuggerP_walk_verts[84] = 1.094096;
        LuggerP_walk_verts[85] = 2.552375;
        LuggerP_walk_verts[86] = 5.687628;
        LuggerP_walk_verts[87] = -1.122626;
        LuggerP_walk_verts[88] = 2.309869;
        LuggerP_walk_verts[89] = 5.785149;
        LuggerP_walk_verts[90] = 0.044755;
        LuggerP_walk_verts[91] = 2.34237;
        LuggerP_walk_verts[92] = 5.453808;
        LuggerP_walk_verts[93] = 0.636691;
        LuggerP_walk_verts[94] = 11.234458;
        LuggerP_walk_verts[95] = -1.089665;
        LuggerP_walk_verts[96] = -0.687716;
        LuggerP_walk_verts[97] = 11.331942;
        LuggerP_walk_verts[98] = -1.171821;
        LuggerP_walk_verts[99] = 2.520456;
        LuggerP_walk_verts[100] = 1.679855;
        LuggerP_walk_verts[101] = -0.365599;
        LuggerP_walk_verts[102] = 2.798997;
        LuggerP_walk_verts[103] = 2.689879;
        LuggerP_walk_verts[104] = -0.412412;
        LuggerP_walk_verts[105] = 3.310396;
        LuggerP_walk_verts[106] = 2.812381;
        LuggerP_walk_verts[107] = -1.237609;
        LuggerP_walk_verts[108] = -0.555148;
        LuggerP_walk_verts[109] = 10.099648;
        LuggerP_walk_verts[110] = 6.791602;
        LuggerP_walk_verts[111] = 0.52809;
        LuggerP_walk_verts[112] = 10.119644;
        LuggerP_walk_verts[113] = 6.770446;
        LuggerP_walk_verts[114] = 2.766795;
        LuggerP_walk_verts[115] = 3.012386;
        LuggerP_walk_verts[116] = 6.612427;
        LuggerP_walk_verts[117] = 1.959249;
        LuggerP_walk_verts[118] = 2.517375;
        LuggerP_walk_verts[119] = 5.529098;
        LuggerP_walk_verts[120] = 2.582923;
        LuggerP_walk_verts[121] = 2.847382;
        LuggerP_walk_verts[122] = 5.676734;
        LuggerP_walk_verts[123] = -2.097512;
        LuggerP_walk_verts[124] = 2.244869;
        LuggerP_walk_verts[125] = 5.509909;
        LuggerP_walk_verts[126] = -2.506261;
        LuggerP_walk_verts[127] = 2.962385;
        LuggerP_walk_verts[128] = 5.72462;
        LuggerP_walk_verts[129] = -2.560056;
        LuggerP_walk_verts[130] = 2.947385;
        LuggerP_walk_verts[131] = 6.531489;
        LuggerP_walk_verts[132] = -2.216551;
        LuggerP_walk_verts[133] = 1.769858;
        LuggerP_walk_verts[134] = -0.863319;
        LuggerP_walk_verts[135] = -2.832934;
        LuggerP_walk_verts[136] = 2.652378;
        LuggerP_walk_verts[137] = -0.559539;
        LuggerP_walk_verts[138] = -3.185151;
        LuggerP_walk_verts[139] = 2.847382;
        LuggerP_walk_verts[140] = -1.20744;
        LuggerP_walk_verts[141] = -1.511729;
        LuggerP_walk_verts[142] = 3.687401;
        LuggerP_walk_verts[143] = -9.243541;
        LuggerP_walk_verts[144] = -2.293585;
        LuggerP_walk_verts[145] = 3.712402;
        LuggerP_walk_verts[146] = -9.62615;
        LuggerP_walk_verts[147] = 2.168569;
        LuggerP_walk_verts[148] = 3.739902;
        LuggerP_walk_verts[149] = -9.794724;
        LuggerP_walk_verts[150] = -0.397166;
        LuggerP_walk_verts[151] = 9.764704;
        LuggerP_walk_verts[152] = -11.439563;
        LuggerP_walk_verts[153] = 0.545383;
        LuggerP_walk_verts[154] = 9.772202;
        LuggerP_walk_verts[155] = -11.529305;

        LuggerP_walk_types[0] = 0;
        LuggerP_walk_types[1] = 0;
        LuggerP_walk_types[2] = 0;
        LuggerP_walk_types[3] = 0;
        LuggerP_walk_types[4] = 0;
        LuggerP_walk_types[5] = 0;
        LuggerP_walk_types[6] = 0;
        LuggerP_walk_types[7] = 0;
        LuggerP_walk_types[8] = 1;
        LuggerP_walk_types[9] = 1;
        LuggerP_walk_types[10] = 1;
        LuggerP_walk_types[11] = 1;
        LuggerP_walk_types[12] = 0;
        LuggerP_walk_types[13] = 0;
        LuggerP_walk_types[14] = 0;
        LuggerP_walk_types[15] = 0;
        LuggerP_walk_types[16] = 0;
        LuggerP_walk_types[17] = 2;
        LuggerP_walk_types[18] = 2;
        LuggerP_walk_types[19] = 2;
        LuggerP_walk_types[20] = 2;
        LuggerP_walk_types[21] = 0;
        LuggerP_walk_types[22] = 0;
        LuggerP_walk_types[23] = 0;
        LuggerP_walk_types[24] = 0;
        LuggerP_walk_types[25] = 0;
        LuggerP_walk_types[26] = 0;
        LuggerP_walk_types[27] = 0;
        LuggerP_walk_types[28] = 3;
        LuggerP_walk_types[29] = 3;
        LuggerP_walk_types[30] = 0;
        LuggerP_walk_types[31] = 4;
        LuggerP_walk_types[32] = 4;
        LuggerP_walk_types[33] = 0;
        LuggerP_walk_types[34] = 0;
        LuggerP_walk_types[35] = 5;
        LuggerP_walk_types[36] = 5;
        LuggerP_walk_types[37] = 5;
        LuggerP_walk_types[38] = 5;
        LuggerP_walk_types[39] = 0;
        LuggerP_walk_types[40] = 0;
        LuggerP_walk_types[41] = 0;
        LuggerP_walk_types[42] = 0;
        LuggerP_walk_types[43] = 5;
        LuggerP_walk_types[44] = 0;
        LuggerP_walk_types[45] = 0;
        LuggerP_walk_types[46] = 5;
        LuggerP_walk_types[47] = 0;
        LuggerP_walk_types[48] = 5;
        LuggerP_walk_types[49] = 5;
        LuggerP_walk_types[50] = 5;
        LuggerP_walk_types[51] = 5;

        LuggerP_walk_graph[0] = (0)*256 + (0);
        LuggerP_walk_graph[1] = (1)*256 + (2);
        LuggerP_walk_graph[2] = (3)*256 + (0);
        LuggerP_walk_graph[3] = (4)*256 + (3);
        LuggerP_walk_graph[4] = (0)*256 + (2);
        LuggerP_walk_graph[5] = (1)*256 + (0);
        LuggerP_walk_graph[6] = (4)*256 + (0);
        LuggerP_walk_graph[7] = (5)*256 + (4);
        LuggerP_walk_graph[8] = (6)*256 + (5);
        LuggerP_walk_graph[9] = (7)*256 + (6);
        LuggerP_walk_graph[10] = (7)*256 + (8);
        LuggerP_walk_graph[11] = (9)*256 + (12);
        LuggerP_walk_graph[12] = (10)*256 + (13);
        LuggerP_walk_graph[13] = (13)*256 + (14);
        LuggerP_walk_graph[14] = (13)*256 + (16);
        LuggerP_walk_graph[15] = (13)*256 + (21);
        LuggerP_walk_graph[16] = (13)*256 + (12);
        LuggerP_walk_graph[17] = (14)*256 + (15);
        LuggerP_walk_graph[18] = (14)*256 + (17);
        LuggerP_walk_graph[19] = (14)*256 + (21);
        LuggerP_walk_graph[20] = (15)*256 + (6);
        LuggerP_walk_graph[21] = (20)*256 + (6);
        LuggerP_walk_graph[22] = (7)*256 + (12);
        LuggerP_walk_graph[23] = (12)*256 + (15);
        LuggerP_walk_graph[24] = (21)*256 + (18);
        LuggerP_walk_graph[25] = (21)*256 + (16);
        LuggerP_walk_graph[26] = (11)*256 + (16);
        LuggerP_walk_graph[27] = (22)*256 + (16);
        LuggerP_walk_graph[28] = (22)*256 + (25);
        LuggerP_walk_graph[29] = (24)*256 + (26);
        LuggerP_walk_graph[30] = (28)*256 + (26);
        LuggerP_walk_graph[31] = (29)*256 + (27);
        LuggerP_walk_graph[32] = (26)*256 + (30);
        LuggerP_walk_graph[33] = (21)*256 + (23);
        LuggerP_walk_graph[34] = (23)*256 + (24);
        LuggerP_walk_graph[35] = (27)*256 + (25);
        LuggerP_walk_graph[36] = (27)*256 + (30);
        LuggerP_walk_graph[37] = (15)*256 + (19);
        LuggerP_walk_graph[38] = (34)*256 + (33);
        LuggerP_walk_graph[39] = (34)*256 + (35);
        LuggerP_walk_graph[40] = (33)*256 + (15);
        LuggerP_walk_graph[41] = (40)*256 + (39);
        LuggerP_walk_graph[42] = (35)*256 + (31);
        LuggerP_walk_graph[43] = (43)*256 + (36);
        LuggerP_walk_graph[44] = (38)*256 + (37);
        LuggerP_walk_graph[45] = (41)*256 + (25);
        LuggerP_walk_graph[46] = (38)*256 + (40);
        LuggerP_walk_graph[47] = (42)*256 + (41);
        LuggerP_walk_graph[48] = (42)*256 + (43);
        LuggerP_walk_graph[49] = (39)*256 + (26);
        LuggerP_walk_graph[50] = (41)*256 + (27);
        LuggerP_walk_graph[51] = (14)*256 + (33);
        LuggerP_walk_graph[52] = (32)*256 + (46);
        LuggerP_walk_graph[53] = (45)*256 + (44);
        LuggerP_walk_graph[54] = (46)*256 + (45);
        LuggerP_walk_graph[55] = (44)*256 + (12);
        LuggerP_walk_graph[56] = (44)*256 + (13);
        LuggerP_walk_graph[57] = (50)*256 + (48);
        LuggerP_walk_graph[58] = (2)*256 + (48);
        LuggerP_walk_graph[59] = (3)*256 + (49);
        LuggerP_walk_graph[60] = (49)*256 + (51);
        LuggerP_walk_graph[61] = (47)*256 + (0);
        LuggerP_walk_graph[62] = (47)*256 + (2);
        LuggerP_walk_graph[63] = (48)*256 + (47);
}
