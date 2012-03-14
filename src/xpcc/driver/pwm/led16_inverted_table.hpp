// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2011, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC__PWM_LED_HPP
#	error	"Don't include this file directly, use 'led.hpp' instead!"
#endif

// ----------------------------------------------------------------------------

namespace xpcc
{
	namespace pwm
	{
		// mathemathical formula for this is:
		// value = (2^16 - (500000/(0.9*step + 358) - 398)*4.096)
		// these values are subtracted from 2^16 because of the way the timer
		// should be set up.
		// Please note the first value is 0xaffe, because then the output
		// compare interrupt never gets triggered, and the LED stays off.
		// This uses 2000 bytes of flash, use Led8 if flash size is important.
		FLASH_STORAGE(uint16_t PwmTable16Inverted[1000]) = {
			0xAFFE,0xFFFF,0xFFFE,0xFFFD,0xFFFC,0xFFFB,0xFFFA,0xFFF8,0xFFF7,0xFFF6,0xFFF5,0xFFF4,0xFFF2,0xFFF1,0xFFF0,0xFFEF,0xFFEE,0xFFEC,0xFFEB,0xFFEA,
			0xFFE9,0xFFE8,0xFFE6,0xFFE5,0xFFE4,0xFFE3,0xFFE2,0xFFE0,0xFFDF,0xFFDE,0xFFDD,0xFFDC,0xFFDA,0xFFD9,0xFFD8,0xFFD7,0xFFD5,0xFFD4,0xFFD3,0xFFD2,
			0xFFD1,0xFFCF,0xFFCE,0xFFCD,0xFFCC,0xFFCA,0xFFC9,0xFFC8,0xFFC7,0xFFC5,0xFFC4,0xFFC3,0xFFC2,0xFFC0,0xFFBF,0xFFBE,0xFFBD,0xFFBB,0xFFBA,0xFFB9,
			0xFFB7,0xFFB6,0xFFB5,0xFFB4,0xFFB2,0xFFB1,0xFFB0,0xFFAE,0xFFAD,0xFFAC,0xFFAB,0xFFA9,0xFFA8,0xFFA7,0xFFA5,0xFFA4,0xFFA3,0xFFA2,0xFFA0,0xFF9F,
			0xFF9E,0xFF9C,0xFF9B,0xFF9A,0xFF98,0xFF97,0xFF96,0xFF94,0xFF93,0xFF92,0xFF90,0xFF8F,0xFF8E,0xFF8C,0xFF8B,0xFF8A,0xFF88,0xFF87,0xFF86,0xFF84,
			0xFF83,0xFF82,0xFF80,0xFF7F,0xFF7E,0xFF7C,0xFF7B,0xFF79,0xFF78,0xFF77,0xFF75,0xFF74,0xFF73,0xFF71,0xFF70,0xFF6E,0xFF6D,0xFF6C,0xFF6A,0xFF69,
			0xFF67,0xFF66,0xFF65,0xFF63,0xFF62,0xFF60,0xFF5F,0xFF5E,0xFF5C,0xFF5B,0xFF59,0xFF58,0xFF57,0xFF55,0xFF54,0xFF52,0xFF51,0xFF4F,0xFF4E,0xFF4D,
			0xFF4B,0xFF4A,0xFF48,0xFF47,0xFF45,0xFF44,0xFF42,0xFF41,0xFF3F,0xFF3E,0xFF3D,0xFF3B,0xFF3A,0xFF38,0xFF37,0xFF35,0xFF34,0xFF32,0xFF31,0xFF2F,
			0xFF2E,0xFF2C,0xFF2B,0xFF29,0xFF28,0xFF26,0xFF25,0xFF23,0xFF22,0xFF20,0xFF1F,0xFF1D,0xFF1C,0xFF1A,0xFF19,0xFF17,0xFF16,0xFF14,0xFF13,0xFF11,
			0xFF10,0xFF0E,0xFF0C,0xFF0B,0xFF09,0xFF08,0xFF06,0xFF05,0xFF03,0xFF02,0xFF00,0xFEFE,0xFEFD,0xFEFB,0xFEFA,0xFEF8,0xFEF7,0xFEF5,0xFEF3,0xFEF2,
			0xFEF0,0xFEEF,0xFEED,0xFEEC,0xFEEA,0xFEE8,0xFEE7,0xFEE5,0xFEE4,0xFEE2,0xFEE0,0xFEDF,0xFEDD,0xFEDB,0xFEDA,0xFED8,0xFED7,0xFED5,0xFED3,0xFED2,
			0xFED0,0xFECE,0xFECD,0xFECB,0xFEC9,0xFEC8,0xFEC6,0xFEC4,0xFEC3,0xFEC1,0xFEBF,0xFEBE,0xFEBC,0xFEBA,0xFEB9,0xFEB7,0xFEB5,0xFEB4,0xFEB2,0xFEB0,
			0xFEAF,0xFEAD,0xFEAB,0xFEA9,0xFEA8,0xFEA6,0xFEA4,0xFEA3,0xFEA1,0xFE9F,0xFE9D,0xFE9C,0xFE9A,0xFE98,0xFE96,0xFE95,0xFE93,0xFE91,0xFE8F,0xFE8E,
			0xFE8C,0xFE8A,0xFE88,0xFE87,0xFE85,0xFE83,0xFE81,0xFE80,0xFE7E,0xFE7C,0xFE7A,0xFE78,0xFE77,0xFE75,0xFE73,0xFE71,0xFE6F,0xFE6E,0xFE6C,0xFE6A,
			0xFE68,0xFE66,0xFE64,0xFE63,0xFE61,0xFE5F,0xFE5D,0xFE5B,0xFE59,0xFE58,0xFE56,0xFE54,0xFE52,0xFE50,0xFE4E,0xFE4C,0xFE4A,0xFE49,0xFE47,0xFE45,
			0xFE43,0xFE41,0xFE3F,0xFE3D,0xFE3B,0xFE39,0xFE38,0xFE36,0xFE34,0xFE32,0xFE30,0xFE2E,0xFE2C,0xFE2A,0xFE28,0xFE26,0xFE24,0xFE22,0xFE20,0xFE1E,
			0xFE1C,0xFE1A,0xFE18,0xFE17,0xFE15,0xFE13,0xFE11,0xFE0F,0xFE0D,0xFE0B,0xFE09,0xFE07,0xFE05,0xFE03,0xFE01,0xFDFF,0xFDFD,0xFDFB,0xFDF8,0xFDF6,
			0xFDF4,0xFDF2,0xFDF0,0xFDEE,0xFDEC,0xFDEA,0xFDE8,0xFDE6,0xFDE4,0xFDE2,0xFDE0,0xFDDE,0xFDDC,0xFDDA,0xFDD8,0xFDD5,0xFDD3,0xFDD1,0xFDCF,0xFDCD,
			0xFDCB,0xFDC9,0xFDC7,0xFDC5,0xFDC2,0xFDC0,0xFDBE,0xFDBC,0xFDBA,0xFDB8,0xFDB5,0xFDB3,0xFDB1,0xFDAF,0xFDAD,0xFDAB,0xFDA8,0xFDA6,0xFDA4,0xFDA2,
			0xFDA0,0xFD9D,0xFD9B,0xFD99,0xFD97,0xFD95,0xFD92,0xFD90,0xFD8E,0xFD8C,0xFD89,0xFD87,0xFD85,0xFD83,0xFD80,0xFD7E,0xFD7C,0xFD7A,0xFD77,0xFD75,
			0xFD73,0xFD71,0xFD6E,0xFD6C,0xFD6A,0xFD67,0xFD65,0xFD63,0xFD60,0xFD5E,0xFD5C,0xFD59,0xFD57,0xFD55,0xFD52,0xFD50,0xFD4E,0xFD4B,0xFD49,0xFD46,
			0xFD44,0xFD42,0xFD3F,0xFD3D,0xFD3A,0xFD38,0xFD36,0xFD33,0xFD31,0xFD2E,0xFD2C,0xFD2A,0xFD27,0xFD25,0xFD22,0xFD20,0xFD1D,0xFD1B,0xFD18,0xFD16,
			0xFD13,0xFD11,0xFD0E,0xFD0C,0xFD09,0xFD07,0xFD04,0xFD02,0xFCFF,0xFCFD,0xFCFA,0xFCF8,0xFCF5,0xFCF3,0xFCF0,0xFCED,0xFCEB,0xFCE8,0xFCE6,0xFCE3,
			0xFCE1,0xFCDE,0xFCDB,0xFCD9,0xFCD6,0xFCD4,0xFCD1,0xFCCE,0xFCCC,0xFCC9,0xFCC6,0xFCC4,0xFCC1,0xFCBE,0xFCBC,0xFCB9,0xFCB6,0xFCB4,0xFCB1,0xFCAE,
			0xFCAC,0xFCA9,0xFCA6,0xFCA3,0xFCA1,0xFC9E,0xFC9B,0xFC98,0xFC96,0xFC93,0xFC90,0xFC8D,0xFC8B,0xFC88,0xFC85,0xFC82,0xFC7F,0xFC7D,0xFC7A,0xFC77,
			0xFC74,0xFC71,0xFC6F,0xFC6C,0xFC69,0xFC66,0xFC63,0xFC60,0xFC5D,0xFC5B,0xFC58,0xFC55,0xFC52,0xFC4F,0xFC4C,0xFC49,0xFC46,0xFC43,0xFC40,0xFC3D,
			0xFC3A,0xFC37,0xFC34,0xFC31,0xFC2E,0xFC2B,0xFC28,0xFC25,0xFC22,0xFC1F,0xFC1C,0xFC19,0xFC16,0xFC13,0xFC10,0xFC0D,0xFC0A,0xFC07,0xFC04,0xFC01,
			0xFBFE,0xFBFB,0xFBF8,0xFBF4,0xFBF1,0xFBEE,0xFBEB,0xFBE8,0xFBE5,0xFBE2,0xFBDE,0xFBDB,0xFBD8,0xFBD5,0xFBD2,0xFBCE,0xFBCB,0xFBC8,0xFBC5,0xFBC2,
			0xFBBE,0xFBBB,0xFBB8,0xFBB4,0xFBB1,0xFBAE,0xFBAB,0xFBA7,0xFBA4,0xFBA1,0xFB9D,0xFB9A,0xFB97,0xFB93,0xFB90,0xFB8D,0xFB89,0xFB86,0xFB82,0xFB7F,
			0xFB7C,0xFB78,0xFB75,0xFB71,0xFB6E,0xFB6B,0xFB67,0xFB64,0xFB60,0xFB5D,0xFB59,0xFB56,0xFB52,0xFB4F,0xFB4B,0xFB48,0xFB44,0xFB40,0xFB3D,0xFB39,
			0xFB36,0xFB32,0xFB2F,0xFB2B,0xFB27,0xFB24,0xFB20,0xFB1C,0xFB19,0xFB15,0xFB11,0xFB0E,0xFB0A,0xFB06,0xFB03,0xFAFF,0xFAFB,0xFAF7,0xFAF4,0xFAF0,
			0xFAEC,0xFAE8,0xFAE5,0xFAE1,0xFADD,0xFAD9,0xFAD5,0xFAD2,0xFACE,0xFACA,0xFAC6,0xFAC2,0xFABE,0xFABA,0xFAB6,0xFAB3,0xFAAF,0xFAAB,0xFAA7,0xFAA3,
			0xFA9F,0xFA9B,0xFA97,0xFA93,0xFA8F,0xFA8B,0xFA87,0xFA83,0xFA7F,0xFA7B,0xFA77,0xFA72,0xFA6E,0xFA6A,0xFA66,0xFA62,0xFA5E,0xFA5A,0xFA56,0xFA51,
			0xFA4D,0xFA49,0xFA45,0xFA41,0xFA3C,0xFA38,0xFA34,0xFA30,0xFA2B,0xFA27,0xFA23,0xFA1E,0xFA1A,0xFA16,0xFA11,0xFA0D,0xFA09,0xFA04,0xFA00,0xF9FB,
			0xF9F7,0xF9F3,0xF9EE,0xF9EA,0xF9E5,0xF9E1,0xF9DC,0xF9D8,0xF9D3,0xF9CF,0xF9CA,0xF9C6,0xF9C1,0xF9BC,0xF9B8,0xF9B3,0xF9AF,0xF9AA,0xF9A5,0xF9A1,
			0xF99C,0xF997,0xF992,0xF98E,0xF989,0xF984,0xF980,0xF97B,0xF976,0xF971,0xF96C,0xF967,0xF963,0xF95E,0xF959,0xF954,0xF94F,0xF94A,0xF945,0xF940,
			0xF93B,0xF936,0xF931,0xF92C,0xF927,0xF922,0xF91D,0xF918,0xF913,0xF90E,0xF909,0xF904,0xF8FF,0xF8FA,0xF8F4,0xF8EF,0xF8EA,0xF8E5,0xF8DF,0xF8DA,
			0xF8D5,0xF8D0,0xF8CA,0xF8C5,0xF8C0,0xF8BA,0xF8B5,0xF8B0,0xF8AA,0xF8A5,0xF89F,0xF89A,0xF894,0xF88F,0xF88A,0xF884,0xF87E,0xF879,0xF873,0xF86E,
			0xF868,0xF863,0xF85D,0xF857,0xF852,0xF84C,0xF846,0xF840,0xF83B,0xF835,0xF82F,0xF829,0xF824,0xF81E,0xF818,0xF812,0xF80C,0xF806,0xF800,0xF7FA,
			0xF7F4,0xF7EE,0xF7E8,0xF7E2,0xF7DC,0xF7D6,0xF7D0,0xF7CA,0xF7C4,0xF7BE,0xF7B7,0xF7B1,0xF7AB,0xF7A5,0xF79F,0xF798,0xF792,0xF78C,0xF785,0xF77F,
			0xF779,0xF772,0xF76C,0xF765,0xF75F,0xF758,0xF752,0xF74B,0xF745,0xF73E,0xF738,0xF731,0xF72A,0xF724,0xF71D,0xF716,0xF710,0xF709,0xF702,0xF6FB,
			0xF6F4,0xF6EE,0xF6E7,0xF6E0,0xF6D9,0xF6D2,0xF6CB,0xF6C4,0xF6BD,0xF6B6,0xF6AF,0xF6A8,0xF6A1,0xF699,0xF692,0xF68B,0xF684,0xF67D,0xF675,0xF66E,
			0xF667,0xF65F,0xF658,0xF651,0xF649,0xF642,0xF63A,0xF633,0xF62B,0xF624,0xF61C,0xF614,0xF60D,0xF605,0xF5FD,0xF5F6,0xF5EE,0xF5E6,0xF5DE,0xF5D6,
			0xF5CE,0xF5C7,0xF5BF,0xF5B7,0xF5AF,0xF5A7,0xF59E,0xF596,0xF58E,0xF586,0xF57E,0xF576,0xF56D,0xF565,0xF55D,0xF555,0xF54C,0xF544,0xF53B,0xF533,
			0xF52A,0xF522,0xF519,0xF511,0xF508,0xF4FF,0xF4F7,0xF4EE,0xF4E5,0xF4DC,0xF4D3,0xF4CB,0xF4C2,0xF4B9,0xF4B0,0xF4A7,0xF49E,0xF495,0xF48B,0xF482,
			0xF479,0xF470,0xF467,0xF45D,0xF454,0xF44B,0xF441,0xF438,0xF42E,0xF425,0xF41B,0xF411,0xF408,0xF3FE,0xF3F4,0xF3EA,0xF3E1,0xF3D7,0xF3CD,0xF3C3,
			0xF3B9,0xF3AF,0xF3A5,0xF39B,0xF391,0xF386,0xF37C,0xF372,0xF367,0xF35D,0xF353,0xF348,0xF33E,0xF333,0xF329,0xF31E,0xF313,0xF308,0xF2FE,0xF2F3,
			0xF2E8,0xF2DD,0xF2D2,0xF2C7,0xF2BC,0xF2B1,0xF2A6,0xF29A,0xF28F,0xF284,0xF278,0xF26D,0xF262,0xF256,0xF24A,0xF23F,0xF233,0xF227,0xF21C,0xF210,
			0xF204,0xF1F8,0xF1EC,0xF1E0,0xF1D4,0xF1C8,0xF1BB,0xF1AF,0xF1A3,0xF196,0xF18A,0xF17D,0xF171,0xF164,0xF157,0xF14B,0xF13E,0xF131,0xF124,0xF117,
			0xF10A,0xF0FD,0xF0F0,0xF0E2,0xF0D5,0xF0C8,0xF0BA,0xF0AD,0xF09F,0xF091,0xF084,0xF076,0xF068,0xF05A,0xF04C,0xF03E,0xF030,0xF022,0xF013,0xF005
		};
		
		xpcc::accessor::Flash<uint16_t> PwmValues16Inverted(PwmTable16Inverted);
	}
}

