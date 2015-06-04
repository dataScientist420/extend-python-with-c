#!/bin/env python

#  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
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
#  File:   setup.py                                                                                                           
#  Author: Victor Neville                                                                                              
#  Date:  31/5/2014                                                                                                                                                                                             
#  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *

from distutils.core import setup, Extension

module = Extension('mymodule', include_dirs=['/usr/local/lib/python2.7'], sources=['mymodule.c'])
setup(name='mymodule', version='1.0', description='Example', author='vic', ext_modules=[module])
