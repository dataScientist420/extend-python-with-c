#!/bin/env python

#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#  @file:   main.py
#  @description: This file tests the extension module "testmodule.c".                                                                                                           
#  @author: Victor Neville                                                                                              
#  @date:  31/5/2014                                                                                                                                                                                             

import testmodule

# Entry Point
if __name__ == '__main__':
	max_val = 20
	val = testmodule.get_int("Enter an integer (max = %d): " % max_val, max_val)
	
	print('fibonacci(%d): %d' % (val, testmodule.fibonacci(val)))
	print('factorial(%d): %d' % (val, testmodule.factorial(val)))
	print('digits_sum(%d): %d' % (val, testmodule.digits_sum(val)))
