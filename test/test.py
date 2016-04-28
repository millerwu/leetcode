import os
import stat

file_name = 'test.py'
file_stats = os.stat(file_name)

file_info = {
	'fi_name':file_name
}

print ("file_name = %(fi_name)s" % file_info)