import sys
import codecs 
sys.stdin= codecs.getreader('utf-8')(sys.stdin)

print(sys.stdin.encoding)
print(sys.stdout.encoding)