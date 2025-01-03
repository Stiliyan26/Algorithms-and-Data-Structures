def isValid_Stack(str: str) -> bool:
  stack = [];
  closeToOpen = { ')': '(', ']': '[', '}': '{'}
  
  for c in str:
    if c in closeToOpen:
      if stack and stack[-1] == closeToOpen[c]:
        stack.pop()
      else:
        return False
    else:
      stack.append(c);
  
  return True if not stack else False;

def isValid_BruteForse(str: str) -> bool:
  while True:
    pos = -1
    
    if "()" in str:
      str = str.replace("()", "", 1)
      continue;
    
    if "[]" in str:
      str = str.replace("[]", "", 1)
      continue
    
    if "{}" in str:
      str = str.replace("{}", "", 1)
      continue
    
    break
  
  return len(str) == 0; 

str_test = "[{()}]"

print(isValid_BruteForse(str_test))