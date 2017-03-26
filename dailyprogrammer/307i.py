lenword = {}
longest = 0

def permutations(word):
  perms = []
  for i in range(len(word)):
    perms.append(word[:i] + word[(i+1):])
  return perms

def derivable(word):
  if len(word) < 3:
    return word in lenword.get(len(word), set())
  for perm in permutations(word):
    if perm in lenword.get(len(perm), set()) and derivable(perm):
      return True
  return False
  

with open("/usr/share/dict/words") as f:
  for word in [w.strip() for w in f]:
    if len(word) > longest:
      longest = len(word)
    if len(word) < 2:
      continue
    if lenword.get(len(word)) is None:
      lenword[len(word)] = set(word)
    else:
      lenword[len(word)].add(word)

for length in reversed(range(8, longest)):
  for word in lenword.get(length, set()):
    if derivable(word):
      print(word)
  else:
    continue
  break

