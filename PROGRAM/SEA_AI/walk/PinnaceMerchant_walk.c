int PinnaceMerchant_walk_count;
float PinnaceMerchant_walk_verts[156];
int PinnaceMerchant_walk_types[52];
int PinnaceMerchant_walk_graph[56];

void PinnaceMerchant_walk_init()
{
        PinnaceMerchant_walk_count = 52;

        PinnaceMerchant_walk_verts[0] = 2.884351;
        PinnaceMerchant_walk_verts[1] = 5.389929;
        PinnaceMerchant_walk_verts[2] = 10.295492;
        PinnaceMerchant_walk_verts[3] = 1.581539;
        PinnaceMerchant_walk_verts[4] = 3.087437;
        PinnaceMerchant_walk_verts[5] = 5.134909;
        PinnaceMerchant_walk_verts[6] = 1.280859;
        PinnaceMerchant_walk_verts[7] = 3.214916;
        PinnaceMerchant_walk_verts[8] = 0.749749;
        PinnaceMerchant_walk_verts[9] = 2.938318;
        PinnaceMerchant_walk_verts[10] = 3.174921;
        PinnaceMerchant_walk_verts[11] = -1.839817;
        PinnaceMerchant_walk_verts[12] = 2.780768;
        PinnaceMerchant_walk_verts[13] = 5.397399;
        PinnaceMerchant_walk_verts[14] = -4.694066;
        PinnaceMerchant_walk_verts[15] = 2.714541;
        PinnaceMerchant_walk_verts[16] = 5.932395;
        PinnaceMerchant_walk_verts[17] = -6.841795;
        PinnaceMerchant_walk_verts[18] = -3.050224;
        PinnaceMerchant_walk_verts[19] = 5.419899;
        PinnaceMerchant_walk_verts[20] = 10.396123;
        PinnaceMerchant_walk_verts[21] = -1.516833;
        PinnaceMerchant_walk_verts[22] = 3.189903;
        PinnaceMerchant_walk_verts[23] = 5.179106;
        PinnaceMerchant_walk_verts[24] = -1.413327;
        PinnaceMerchant_walk_verts[25] = 3.134904;
        PinnaceMerchant_walk_verts[26] = 0.774558;
        PinnaceMerchant_walk_verts[27] = -2.99977;
        PinnaceMerchant_walk_verts[28] = 3.164904;
        PinnaceMerchant_walk_verts[29] = -1.901514;
        PinnaceMerchant_walk_verts[30] = -2.702097;
        PinnaceMerchant_walk_verts[31] = 5.662398;
        PinnaceMerchant_walk_verts[32] = -4.623868;
        PinnaceMerchant_walk_verts[33] = -2.745002;
        PinnaceMerchant_walk_verts[34] = 5.982537;
        PinnaceMerchant_walk_verts[35] = -7.179287;
        PinnaceMerchant_walk_verts[36] = -0.223301;
        PinnaceMerchant_walk_verts[37] = 6.125047;
        PinnaceMerchant_walk_verts[38] = -7.48538;
        PinnaceMerchant_walk_verts[39] = -2.524123;
        PinnaceMerchant_walk_verts[40] = 7.400037;
        PinnaceMerchant_walk_verts[41] = -12.447815;
        PinnaceMerchant_walk_verts[42] = 2.589172;
        PinnaceMerchant_walk_verts[43] = 7.287543;
        PinnaceMerchant_walk_verts[44] = -12.54295;
        PinnaceMerchant_walk_verts[45] = 4.959882;
        PinnaceMerchant_walk_verts[46] = 5.445043;
        PinnaceMerchant_walk_verts[47] = -7.115979;
        PinnaceMerchant_walk_verts[48] = 4.87294;
        PinnaceMerchant_walk_verts[49] = 5.30004;
        PinnaceMerchant_walk_verts[50] = -4.630862;
        PinnaceMerchant_walk_verts[51] = -5.025344;
        PinnaceMerchant_walk_verts[52] = 5.465009;
        PinnaceMerchant_walk_verts[53] = -7.146873;
        PinnaceMerchant_walk_verts[54] = -5.058884;
        PinnaceMerchant_walk_verts[55] = 5.277506;
        PinnaceMerchant_walk_verts[56] = -4.509889;
        PinnaceMerchant_walk_verts[57] = 2.853899;
        PinnaceMerchant_walk_verts[58] = 3.090022;
        PinnaceMerchant_walk_verts[59] = 0.777474;
        PinnaceMerchant_walk_verts[60] = 2.816112;
        PinnaceMerchant_walk_verts[61] = 3.140018;
        PinnaceMerchant_walk_verts[62] = 5.163869;
        PinnaceMerchant_walk_verts[63] = 2.034662;
        PinnaceMerchant_walk_verts[64] = 5.760005;
        PinnaceMerchant_walk_verts[65] = 14.330739;
        PinnaceMerchant_walk_verts[66] = -2.814733;
        PinnaceMerchant_walk_verts[67] = 3.057519;
        PinnaceMerchant_walk_verts[68] = 0.686203;
        PinnaceMerchant_walk_verts[69] = -2.82794;
        PinnaceMerchant_walk_verts[70] = 3.15252;
        PinnaceMerchant_walk_verts[71] = 5.244538;
        PinnaceMerchant_walk_verts[72] = -2.165473;
        PinnaceMerchant_walk_verts[73] = 5.845009;
        PinnaceMerchant_walk_verts[74] = 14.362803;
        PinnaceMerchant_walk_verts[75] = 2.693324;
        PinnaceMerchant_walk_verts[76] = 6.647513;
        PinnaceMerchant_walk_verts[77] = -11.610084;
        PinnaceMerchant_walk_verts[78] = -2.639215;
        PinnaceMerchant_walk_verts[79] = 6.650014;
        PinnaceMerchant_walk_verts[80] = -11.677499;
        PinnaceMerchant_walk_verts[81] = 2.270748;
        PinnaceMerchant_walk_verts[82] = 7.747508;
        PinnaceMerchant_walk_verts[83] = -14.826439;
        PinnaceMerchant_walk_verts[84] = -2.489793;
        PinnaceMerchant_walk_verts[85] = 7.777505;
        PinnaceMerchant_walk_verts[86] = -14.809518;
        PinnaceMerchant_walk_verts[87] = -0.048717;
        PinnaceMerchant_walk_verts[88] = 3.00002;
        PinnaceMerchant_walk_verts[89] = -0.634492;
        PinnaceMerchant_walk_verts[90] = 3.077484;
        PinnaceMerchant_walk_verts[91] = 3.205019;
        PinnaceMerchant_walk_verts[92] = 7.566507;
        PinnaceMerchant_walk_verts[93] = -3.179656;
        PinnaceMerchant_walk_verts[94] = 3.07752;
        PinnaceMerchant_walk_verts[95] = 7.545816;
        PinnaceMerchant_walk_verts[96] = 2.281631;
        PinnaceMerchant_walk_verts[97] = 3.030018;
        PinnaceMerchant_walk_verts[98] = -0.593567;
        PinnaceMerchant_walk_verts[99] = -2.313722;
        PinnaceMerchant_walk_verts[100] = 3.067518;
        PinnaceMerchant_walk_verts[101] = -0.632989;
        PinnaceMerchant_walk_verts[102] = -0.059228;
        PinnaceMerchant_walk_verts[103] = 2.952511;
        PinnaceMerchant_walk_verts[104] = 3.513722;
        PinnaceMerchant_walk_verts[105] = 0.365348;
        PinnaceMerchant_walk_verts[106] = 25.262608;
        PinnaceMerchant_walk_verts[107] = -4.475377;
        PinnaceMerchant_walk_verts[108] = -0.309684;
        PinnaceMerchant_walk_verts[109] = 25.235142;
        PinnaceMerchant_walk_verts[110] = -4.414339;
        PinnaceMerchant_walk_verts[111] = -4.821182;
        PinnaceMerchant_walk_verts[112] = 5.390001;
        PinnaceMerchant_walk_verts[113] = 12.085891;
        PinnaceMerchant_walk_verts[114] = 4.987321;
        PinnaceMerchant_walk_verts[115] = 5.227498;
        PinnaceMerchant_walk_verts[116] = 10.440243;
        PinnaceMerchant_walk_verts[117] = -5.063355;
        PinnaceMerchant_walk_verts[118] = 5.185;
        PinnaceMerchant_walk_verts[119] = 10.152646;
        PinnaceMerchant_walk_verts[120] = 5.056334;
        PinnaceMerchant_walk_verts[121] = 5.302497;
        PinnaceMerchant_walk_verts[122] = 11.803194;
        PinnaceMerchant_walk_verts[123] = 0.377955;
        PinnaceMerchant_walk_verts[124] = 21.090014;
        PinnaceMerchant_walk_verts[125] = 12.504043;
        PinnaceMerchant_walk_verts[126] = -0.378236;
        PinnaceMerchant_walk_verts[127] = 21.137648;
        PinnaceMerchant_walk_verts[128] = 12.569428;
        PinnaceMerchant_walk_verts[129] = -2.289784;
        PinnaceMerchant_walk_verts[130] = 8.445002;
        PinnaceMerchant_walk_verts[131] = -18.256815;
        PinnaceMerchant_walk_verts[132] = 1.917647;
        PinnaceMerchant_walk_verts[133] = 8.502505;
        PinnaceMerchant_walk_verts[134] = -18.379578;
        PinnaceMerchant_walk_verts[135] = -1.533031;
        PinnaceMerchant_walk_verts[136] = 9.337509;
        PinnaceMerchant_walk_verts[137] = -21.843094;
        PinnaceMerchant_walk_verts[138] = 1.589864;
        PinnaceMerchant_walk_verts[139] = 9.287494;
        PinnaceMerchant_walk_verts[140] = -21.740522;
        PinnaceMerchant_walk_verts[141] = -0.111257;
        PinnaceMerchant_walk_verts[142] = 5.495008;
        PinnaceMerchant_walk_verts[143] = 11.621614;
        PinnaceMerchant_walk_verts[144] = 4.324237;
        PinnaceMerchant_walk_verts[145] = 8.29;
        PinnaceMerchant_walk_verts[146] = -18.419447;
        PinnaceMerchant_walk_verts[147] = -4.203924;
        PinnaceMerchant_walk_verts[148] = 8.385;
        PinnaceMerchant_walk_verts[149] = -18.248133;
        PinnaceMerchant_walk_verts[150] = 0.333805;
        PinnaceMerchant_walk_verts[151] = 21.332285;
        PinnaceMerchant_walk_verts[152] = -18.727087;
        PinnaceMerchant_walk_verts[153] = -0.307818;
        PinnaceMerchant_walk_verts[154] = 21.399761;
        PinnaceMerchant_walk_verts[155] = -18.711334;

        PinnaceMerchant_walk_types[0] = 0;
        PinnaceMerchant_walk_types[1] = 0;
        PinnaceMerchant_walk_types[2] = 0;
        PinnaceMerchant_walk_types[3] = 0;
        PinnaceMerchant_walk_types[4] = 0;
        PinnaceMerchant_walk_types[5] = 0;
        PinnaceMerchant_walk_types[6] = 0;
        PinnaceMerchant_walk_types[7] = 0;
        PinnaceMerchant_walk_types[8] = 0;
        PinnaceMerchant_walk_types[9] = 0;
        PinnaceMerchant_walk_types[10] = 0;
        PinnaceMerchant_walk_types[11] = 0;
        PinnaceMerchant_walk_types[12] = 0;
        PinnaceMerchant_walk_types[13] = 0;
        PinnaceMerchant_walk_types[14] = 0;
        PinnaceMerchant_walk_types[15] = 5;
        PinnaceMerchant_walk_types[16] = 5;
        PinnaceMerchant_walk_types[17] = 5;
        PinnaceMerchant_walk_types[18] = 5;
        PinnaceMerchant_walk_types[19] = 2;
        PinnaceMerchant_walk_types[20] = 2;
        PinnaceMerchant_walk_types[21] = 3;
        PinnaceMerchant_walk_types[22] = 1;
        PinnaceMerchant_walk_types[23] = 1;
        PinnaceMerchant_walk_types[24] = 3;
        PinnaceMerchant_walk_types[25] = 0;
        PinnaceMerchant_walk_types[26] = 0;
        PinnaceMerchant_walk_types[27] = 0;
        PinnaceMerchant_walk_types[28] = 0;
        PinnaceMerchant_walk_types[29] = 0;
        PinnaceMerchant_walk_types[30] = 0;
        PinnaceMerchant_walk_types[31] = 0;
        PinnaceMerchant_walk_types[32] = 0;
        PinnaceMerchant_walk_types[33] = 0;
        PinnaceMerchant_walk_types[34] = 0;
        PinnaceMerchant_walk_types[35] = 4;
        PinnaceMerchant_walk_types[36] = 4;
        PinnaceMerchant_walk_types[37] = 5;
        PinnaceMerchant_walk_types[38] = 5;
        PinnaceMerchant_walk_types[39] = 5;
        PinnaceMerchant_walk_types[40] = 5;
        PinnaceMerchant_walk_types[41] = 6;
        PinnaceMerchant_walk_types[42] = 6;
        PinnaceMerchant_walk_types[43] = 0;
        PinnaceMerchant_walk_types[44] = 0;
        PinnaceMerchant_walk_types[45] = 0;
        PinnaceMerchant_walk_types[46] = 0;
        PinnaceMerchant_walk_types[47] = 0;
        PinnaceMerchant_walk_types[48] = 5;
        PinnaceMerchant_walk_types[49] = 5;
        PinnaceMerchant_walk_types[50] = 4;
        PinnaceMerchant_walk_types[51] = 4;

        PinnaceMerchant_walk_graph[0] = (30)*256 + (1);
        PinnaceMerchant_walk_graph[1] = (1)*256 + (2);
        PinnaceMerchant_walk_graph[2] = (32)*256 + (3);
        PinnaceMerchant_walk_graph[3] = (3)*256 + (4);
        PinnaceMerchant_walk_graph[4] = (4)*256 + (5);
        PinnaceMerchant_walk_graph[5] = (31)*256 + (6);
        PinnaceMerchant_walk_graph[6] = (8)*256 + (7);
        PinnaceMerchant_walk_graph[7] = (9)*256 + (33);
        PinnaceMerchant_walk_graph[8] = (10)*256 + (9);
        PinnaceMerchant_walk_graph[9] = (11)*256 + (10);
        PinnaceMerchant_walk_graph[10] = (12)*256 + (11);
        PinnaceMerchant_walk_graph[11] = (33)*256 + (8);
        PinnaceMerchant_walk_graph[12] = (27)*256 + (14);
        PinnaceMerchant_walk_graph[13] = (26)*256 + (13);
        PinnaceMerchant_walk_graph[14] = (5)*256 + (15);
        PinnaceMerchant_walk_graph[15] = (16)*256 + (15);
        PinnaceMerchant_walk_graph[16] = (17)*256 + (11);
        PinnaceMerchant_walk_graph[17] = (17)*256 + (18);
        PinnaceMerchant_walk_graph[18] = (2)*256 + (19);
        PinnaceMerchant_walk_graph[19] = (1)*256 + (20);
        PinnaceMerchant_walk_graph[20] = (0)*256 + (21);
        PinnaceMerchant_walk_graph[21] = (8)*256 + (22);
        PinnaceMerchant_walk_graph[22] = (7)*256 + (23);
        PinnaceMerchant_walk_graph[23] = (6)*256 + (24);
        PinnaceMerchant_walk_graph[24] = (25)*256 + (5);
        PinnaceMerchant_walk_graph[25] = (26)*256 + (11);
        PinnaceMerchant_walk_graph[26] = (32)*256 + (29);
        PinnaceMerchant_walk_graph[27] = (33)*256 + (29);
        PinnaceMerchant_walk_graph[28] = (30)*256 + (0);
        PinnaceMerchant_walk_graph[29] = (31)*256 + (7);
        PinnaceMerchant_walk_graph[30] = (27)*256 + (28);
        PinnaceMerchant_walk_graph[31] = (13)*256 + (28);
        PinnaceMerchant_walk_graph[32] = (25)*256 + (14);
        PinnaceMerchant_walk_graph[33] = (12)*256 + (5);
        PinnaceMerchant_walk_graph[34] = (32)*256 + (2);
        PinnaceMerchant_walk_graph[35] = (1)*256 + (34);
        PinnaceMerchant_walk_graph[36] = (7)*256 + (34);
        PinnaceMerchant_walk_graph[37] = (29)*256 + (34);
        PinnaceMerchant_walk_graph[38] = (16)*256 + (35);
        PinnaceMerchant_walk_graph[39] = (36)*256 + (18);
        PinnaceMerchant_walk_graph[40] = (0)*256 + (38);
        PinnaceMerchant_walk_graph[41] = (40)*256 + (38);
        PinnaceMerchant_walk_graph[42] = (40)*256 + (41);
        PinnaceMerchant_walk_graph[43] = (6)*256 + (39);
        PinnaceMerchant_walk_graph[44] = (37)*256 + (39);
        PinnaceMerchant_walk_graph[45] = (37)*256 + (42);
        PinnaceMerchant_walk_graph[46] = (43)*256 + (28);
        PinnaceMerchant_walk_graph[47] = (43)*256 + (45);
        PinnaceMerchant_walk_graph[48] = (46)*256 + (44);
        PinnaceMerchant_walk_graph[49] = (27)*256 + (44);
        PinnaceMerchant_walk_graph[50] = (47)*256 + (6);
        PinnaceMerchant_walk_graph[51] = (47)*256 + (0);
        PinnaceMerchant_walk_graph[52] = (48)*256 + (44);
        PinnaceMerchant_walk_graph[53] = (48)*256 + (50);
        PinnaceMerchant_walk_graph[54] = (49)*256 + (51);
        PinnaceMerchant_walk_graph[55] = (49)*256 + (43);
}