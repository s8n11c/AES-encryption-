import base64
import hashlib
from Crypto import Random
from Crypto.Cipher import AES

bs = 32
def encrypt(raw,key):
    key=hashlib.sha256(key.encode()).digest()
    raw = pad(raw)
    iv = Random.new().read(AES.block_size)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    return base64.b64encode(iv + cipher.encrypt(raw))

def decrypt( enc , key):
    key=hashlib.sha256(key.encode()).digest()
    enc = base64.b64decode(enc)
    iv = enc[:AES.block_size]
    cipher = AES.new(key, AES.MODE_CBC, iv)
    return unpad(cipher.decrypt(enc[AES.block_size:])).decode('utf-8')  

def pad( s):
    return s + (bs - len(s) % bs) * chr(bs - len(s) % bs)    


def unpad(s):
    return s[:-ord(s[len(s)-1:])]

'''
a=encrypt("welcome to this world","amr")

print "the encrypted text is ",a

print "unecrypted text",decrypt(a,"amr")'''