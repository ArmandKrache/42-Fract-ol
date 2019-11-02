/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:08:47 by akrache           #+#    #+#             */
/*   Updated: 2019/02/05 17:48:35 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract.h"

static void	ft_init_pal6(t_fract *tab)
{
	tab->pal2[40] = 0xa03800;
	tab->pal2[41] = 0xa43900;
	tab->pal2[42] = 0xa83b00;
	tab->pal2[43] = 0xac3c00;
	tab->pal2[44] = 0xb03e00;
	tab->pal2[45] = 0xb43f00;
	tab->pal2[46] = 0xb84000;
	tab->pal2[47] = 0xbc4200;
	tab->pal2[48] = 0xc04300;
	tab->pal2[49] = 0xc44500;
	tab->pal2[50] = 0xc84600;
	tab->pal2[51] = 0xcc4800;
	tab->pal2[52] = 0xd04900;
	tab->pal2[53] = 0xd44a00;
	tab->pal2[54] = 0xd84c00;
	tab->pal2[55] = 0xdc4d00;
	tab->pal2[56] = 0xe04f00;
	tab->pal2[57] = 0xe45000;
	tab->pal2[58] = 0xe85100;
	tab->pal2[59] = 0xec5300;
	tab->pal2[60] = 0xf05400;
	tab->pal2[61] = 0xf45600;
	tab->pal2[62] = 0xf85700;
	tab->pal2[63] = 0xfd5900;
}

static void	ft_init_pal5(t_fract *tab)
{
	tab->pal2[17] = 0x441800;
	tab->pal2[18] = 0x481900;
	tab->pal2[19] = 0x4c1a00;
	tab->pal2[20] = 0x501c00;
	tab->pal2[21] = 0x541d00;
	tab->pal2[22] = 0x581f00;
	tab->pal2[23] = 0x5c2000;
	tab->pal2[24] = 0x602100;
	tab->pal2[25] = 0x642300;
	tab->pal2[26] = 0x682400;
	tab->pal2[27] = 0x6c2600;
	tab->pal2[28] = 0x702700;
	tab->pal2[29] = 0x742800;
	tab->pal2[30] = 0x782a00;
	tab->pal2[31] = 0x7c2b00;
	tab->pal2[32] = 0x802d00;
	tab->pal2[33] = 0x842e00;
	tab->pal2[34] = 0x883000;
	tab->pal2[35] = 0x8c3100;
	tab->pal2[36] = 0x903200;
	tab->pal2[37] = 0x943400;
	tab->pal2[38] = 0x983500;
	tab->pal2[39] = 0x9c3700;
	ft_init_pal6(tab);
}

int			ft_init_pal4(t_fract *tab)
{
	int *pal;

	if (!(pal = (int *)malloc(sizeof(int) * 64)))
		return (0);
	tab->pal2 = pal;
	tab->pal2[0] = 0x000000;
	tab->pal2[1] = 0x040100;
	tab->pal2[2] = 0x080200;
	tab->pal2[3] = 0x0c0400;
	tab->pal2[4] = 0x100500;
	tab->pal2[5] = 0x140700;
	tab->pal2[6] = 0x180800;
	tab->pal2[7] = 0x1c0900;
	tab->pal2[8] = 0x200b00;
	tab->pal2[9] = 0x240c00;
	tab->pal2[10] = 0x280e00;
	tab->pal2[11] = 0x2c0f00;
	tab->pal2[12] = 0x301000;
	tab->pal2[13] = 0x341200;
	tab->pal2[14] = 0x381300;
	tab->pal2[15] = 0x3c1500;
	tab->pal2[16] = 0x401600;
	ft_init_pal5(tab);
	return (1);
}
