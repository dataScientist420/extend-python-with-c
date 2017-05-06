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
#  File:   setup.py
#  Description: This file implements the build script of "testmodule.c".                                                                                                          
#  Author: Victor Neville                                                                                              
#  Date:  31/5/2014                                                                                                                                                                                             

from distutils.core import setup, Extension

# create a new module extension 
module = Extension('testmodule', include_dirs=['/usr/local/lib/python3.5'], \
					sources=['src/testmodule.c'])

# setup the new module extension
setup(name='testmodule', version='1.0', description='module example', \
		author='vic', ext_modules=[module])
