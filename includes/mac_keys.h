/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgirard- <jgirard-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:24:06 by jgirard-          #+#    #+#             */
/*   Updated: 2022/11/16 11:08:42 by jgirard-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_KEYS_H
# define MAC_KEYS_H

typedef	struct	s_key
{
	int			k_esc;
	int			k_la;
	int			k_ra;
	int			k_ua;
	int			k_da;
	int			k_a;
	int			k_b;
	int			k_c;
	int			k_d;
	int			k_e;
	int			k_f;
	int			k_g;
	int			k_h;
	int			k_i;
	int			k_j;
	int			k_k;
	int			k_l;
	int			k_m;
	int			k_n;
	int			k_o;
	int			k_p;
	int			k_q;
	int			k_r;
	int			k_s;
	int			k_t;
	int			k_u;
	int			k_v;
	int			k_w;
	int			k_x;
	int			k_y;
	int			k_z;
	int			k_0;
	int			k_1;
	int			k_2;
	int			k_3;
	int			k_4;
	int			k_5;
	int			k_6;
	int			k_7;
	int			k_8;
	int			k_9;
	int			k_n0;
	int			k_n1;
	int			k_n2;
	int			k_n3;
	int			k_n4;
	int			k_n5;
	int			k_n6;
	int			k_n7;
	int			k_n8;
	int			k_n9;
	int			k_nsla;
	int			k_nstr;
	int			k_nmin;
	int			k_nplu;
	int			k_nent;
	int			k_ndot;
	int			k_nequ;
	int			k_ndel;
	int			k_home;
	int			k_end;
	int			k_pgu;
	int			k_pgd;
	int			k_del;
	int			k_bsp;
	int			k_spc;
	int			k_lshi;
	int			k_rshi;
	int			k_lctrl;
	int			k_rctrl;
	int			k_lopt;
	int			k_ropt;
	int			k_lcmd;
	int			k_rcmd;
	int			k_com;
	int			k_dot;
	int			k_sla;
	int			k_scol;
	int			k_quo;
	int			k_lbra;
	int			k_rbra;
	int			k_bsla;
	int			k_dash;
	int			k_equ;
	int			k_apo;
	int			k_tab;
	int			k_caps;
	int			k_ret;
	int			k_fn;
	int			k_f1;
	int			k_f2;
	int			k_f3;
	int			k_f4;
	int			k_f5;
	int			k_f6;
	int			k_f7;
	int			k_f8;
	int			k_f9;
	int			k_f10;
	int			k_f11;
	int			k_f12;
	int			k_f13;
	int			k_f14;
	int			k_f15;
	int			k_f16;
	int			k_f17;
	int			k_f18;
	int			k_f19;
}				t_key;

/*
****	MACOS KEYS DEFINE	****
*/
# define K_ESC						53
# define K_LA						123
# define K_RA						124
# define K_UA						126
# define K_DA						125
# define K_A						0
# define K_B						11
# define K_C						8
# define K_D						2
# define K_E						14
# define K_F						3
# define K_G						5
# define K_H						4
# define K_I						34
# define K_J						38
# define K_K						40
# define K_L						37
# define K_M						46
# define K_N						45
# define K_O						31
# define K_P						35
# define K_Q						12
# define K_R						15
# define K_S						1
# define K_T						17
# define K_U						32
# define K_V						9
# define K_W						13
# define K_X						7
# define K_Y						16
# define K_Z						6
# define K_0						29
# define K_1						18
# define K_2						19
# define K_3						20
# define K_4						21
# define K_5						23
# define K_6						22
# define K_7						26
# define K_8						28
# define K_9						25
# define K_N0						82
# define K_N1						83
# define K_N2						84
# define K_N3						85
# define K_N4						86
# define K_N5						87
# define K_N6						88
# define K_N7						89
# define K_N8						91
# define K_N9						92
# define K_NSLA						75
# define K_NSTR						67
# define K_NMIN						78
# define K_NPLU						69
# define K_NENT						76
# define K_NDOT						65
# define K_NEQU						81
# define K_NDEL						71
# define K_HOME						115
# define K_END						119
# define K_PGU						116
# define K_PGD						121
# define K_DEL						117
# define K_BSP						51
# define K_SPC						49
# define K_LSHI						257
# define K_RSHI						258
# define K_LCTRL					256
# define K_RCTRL					269
# define K_LOPT						261
# define K_ROPT						262
# define K_LCMD						259
# define K_RCMD						260
# define K_COM						43
# define K_DOT						47
# define K_SLA						44
# define K_SCOL						41
# define K_QUO						39
# define K_LBRA						33
# define K_RBRA						30
# define K_BSLA						51
# define K_DASH						27
# define K_EQU						24
# define K_APO						50
# define K_TAB						48
# define K_CAPS						272
# define K_RET						36
# define K_FN						279
# define K_F1						122
# define K_F2						120
# define K_F3						99
# define K_F4						118
# define K_F5						96
# define K_F6						97
# define K_F7						98
# define K_F8						100
# define K_F9						101
# define K_F10						109
# define K_F11						103
# define K_F12						111
# define K_F13						105
# define K_F14						107
# define K_F15						113
# define K_F16						106
# define K_F17						64
# define K_F18						79
# define K_F19						80
# define KP_ESC						e->keys.k_esc
# define KP_LA						e->keys.k_la
# define KP_RA						e->keys.k_ra
# define KP_UA						e->keys.k_ua
# define KP_DA						e->keys.k_da
# define KP_A						e->keys.k_a
# define KP_B						e->keys.k_b
# define KP_C						e->keys.k_c
# define KP_D						e->keys.k_d
# define KP_E						e->keys.k_e
# define KP_F						e->keys.k_f
# define KP_G						e->keys.k_g
# define KP_H						e->keys.k_h
# define KP_I						e->keys.k_i
# define KP_J						e->keys.k_j
# define KP_K						e->keys.k_k
# define KP_L						e->keys.k_l
# define KP_M						e->keys.k_m
# define KP_N						e->keys.k_n
# define KP_O						e->keys.k_o
# define KP_P						e->keys.k_p
# define KP_Q						e->keys.k_q
# define KP_R						e->keys.k_r
# define KP_S						e->keys.k_s
# define KP_T						e->keys.k_t
# define KP_U						e->keys.k_u
# define KP_V						e->keys.k_v
# define KP_W						e->keys.k_w
# define KP_X						e->keys.k_x
# define KP_Y						e->keys.k_y
# define KP_Z						e->keys.k_z
# define KP_0						e->keys.k_0
# define KP_1						e->keys.k_1
# define KP_2						e->keys.k_2
# define KP_3						e->keys.k_3
# define KP_4						e->keys.k_4
# define KP_5						e->keys.k_5
# define KP_6						e->keys.k_6
# define KP_7						e->keys.k_7
# define KP_8						e->keys.k_8
# define KP_9						e->keys.k_9
# define KP_N0						e->keys.k_n0
# define KP_N1						e->keys.k_n1
# define KP_N2						e->keys.k_n2
# define KP_N3						e->keys.k_n3
# define KP_N4						e->keys.k_n4
# define KP_N5						e->keys.k_n5
# define KP_N6						e->keys.k_n6
# define KP_N7						e->keys.k_n7
# define KP_N8						e->keys.k_n8
# define KP_N9						e->keys.k_n9
# define KP_NSLA					e->keys.k_nsla
# define KP_NSTR					e->keys.k_nstr
# define KP_NMIN					e->keys.k_nmin
# define KP_NPLU					e->keys.k_nplu
# define KP_NENT					e->keys.k_nent
# define KP_NDOT					e->keys.k_ndot
# define KP_NEQU					e->keys.k_nequ
# define KP_NDEL					e->keys.k_ndel
# define KP_HOME					e->keys.k_home
# define KP_END						e->keys.k_end
# define KP_PGU						e->keys.k_pgu
# define KP_PGD						e->keys.k_pgd
# define KP_DEL						e->keys.k_del
# define KP_BSP						e->keys.k_bsp
# define KP_SPC						e->keys.k_spc
# define KP_LSHI					e->keys.k_lshi
# define KP_RSHI					e->keys.k_rshi
# define KP_LCTRL					e->keys.k_lctrl
# define KP_RCTRL					e->keys.k_rctrl
# define KP_LOPT					e->keys.k_lopt
# define KP_ROPT					e->keys.k_ropt
# define KP_LCMD					e->keys.k_lcmd
# define KP_RCMD					e->keys.k_rcmd
# define KP_COM						e->keys.k_com
# define KP_DOT						e->keys.k_dot
# define KP_SLA						e->keys.k_sla
# define KP_SCOL					e->keys.k_scol
# define KP_QUO						e->keys.k_quo
# define KP_LBRA					e->keys.k_lbra
# define KP_RBRA					e->keys.k_rbra
# define KP_BSLA					e->keys.k_bsla
# define KP_DASH					e->keys.k_dash
# define KP_EQU						e->keys.k_equ
# define KP_APO						e->keys.k_apo
# define KP_TAB						e->keys.k_tab
# define KP_CAP						e->keys.k_cap
# define KP_RET						e->keys.k_ret
# define KP_FN						e->keys.k_fn
# define KP_F1						e->keys.k_f1
# define KP_F2						e->keys.k_f2
# define KP_F3						e->keys.k_f3
# define KP_F4						e->keys.k_f4
# define KP_F5						e->keys.k_f5
# define KP_F6						e->keys.k_f6
# define KP_F7						e->keys.k_f7
# define KP_F8						e->keys.k_f8
# define KP_F9						e->keys.k_f9
# define KP_F10						e->keys.k_f10
# define KP_F11						e->keys.k_f11
# define KP_F12						e->keys.k_f12
# define KP_F13						e->keys.k_f13
# define KP_F14						e->keys.k_f14
# define KP_F15						e->keys.k_f15
# define KP_F16						e->keys.k_f16
# define KP_F17						e->keys.k_f17
# define KP_F18						e->keys.k_f18
# define KP_F19						e->keys.k_f19

#endif
