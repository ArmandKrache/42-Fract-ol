/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:47 by akrache           #+#    #+#             */
/*   Updated: 2019/02/05 17:48:39 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_init_pal3(t_fract *tab)
{
	tab->pal[40] = 0xa1815d;
	tab->pal[41] = 0xa58359;
	tab->pal[42] = 0xaa8555;
	tab->pal[43] = 0xae8750;
	tab->pal[44] = 0xb28a4c;
	tab->pal[45] = 0xb68c48;
	tab->pal[46] = 0xba8e44;
	tab->pal[47] = 0xbe9040;
	tab->pal[48] = 0xc2923c;
	tab->pal[49] = 0xc69538;
	tab->pal[50] = 0xca9734;
	tab->pal[51] = 0xce9930;
	tab->pal[52] = 0xd29b2c;
	tab->pal[53] = 0xd69d28;
	tab->pal[54] = 0xdaa024;
	tab->pal[55] = 0xdea220;
	tab->pal[56] = 0xe2a41c;
	tab->pal[57] = 0xe6a618;
	tab->pal[58] = 0xeaa814;
	tab->pal[59] = 0xeeab10;
	tab->pal[60] = 0xf2ad0c;
	tab->pal[61] = 0xf6af08;
	tab->pal[62] = 0xfab104;
	tab->pal[63] = 0xffb400;
}

static void	ft_init_pal2(t_fract *tab)
{
	tab->pal[17] = 0x444eba;
	tab->pal[18] = 0x4850b6;
	tab->pal[19] = 0x4c52b2;
	tab->pal[20] = 0x5055ae;
	tab->pal[21] = 0x5557aa;
	tab->pal[22] = 0x5959a5;
	tab->pal[23] = 0x5d5ba1;
	tab->pal[24] = 0x615d9d;
	tab->pal[25] = 0x656099;
	tab->pal[26] = 0x696295;
	tab->pal[27] = 0x6d6491;
	tab->pal[28] = 0x71668d;
	tab->pal[29] = 0x756889;
	tab->pal[30] = 0x796b85;
	tab->pal[31] = 0x7d6d81;
	tab->pal[32] = 0x816f7d;
	tab->pal[33] = 0x857179;
	tab->pal[34] = 0x897475;
	tab->pal[35] = 0x8d7671;
	tab->pal[36] = 0x91786d;
	tab->pal[37] = 0x957a69;
	tab->pal[38] = 0x997c65;
	tab->pal[39] = 0x9d7f61;
	ft_init_pal3(tab);
}

int			ft_init_pal(t_fract *tab)
{
	int *pal;

	if (!(pal = (int *)malloc(sizeof(int) * 64)))
		return (0);
	tab->pal = pal;
	tab->pal[0] = 0x0029ff;
	tab->pal[1] = 0x042bfa;
	tab->pal[2] = 0x082df6;
	tab->pal[3] = 0x0c2ff2;
	tab->pal[4] = 0x1031ee;
	tab->pal[5] = 0x1434ea;
	tab->pal[6] = 0x1836e6;
	tab->pal[7] = 0x1c38e2;
	tab->pal[8] = 0x203ade;
	tab->pal[9] = 0x243cda;
	tab->pal[10] = 0x283fd6;
	tab->pal[11] = 0x2c41d2;
	tab->pal[12] = 0x3043ce;
	tab->pal[13] = 0x3445ca;
	tab->pal[14] = 0x3847c6;
	tab->pal[15] = 0x3c4ac2;
	tab->pal[16] = 0x404cbe;
	ft_init_pal2(tab);
	return (1);
}
