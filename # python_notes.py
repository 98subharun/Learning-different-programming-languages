#python_notes.py
#Complete Python Learning Reference with Examples

# 1. Hello World
print("1) Hello, World!\n")  # Print output to console

# 2. Variables and Data Types
i = 10                      # Integer
d = 3.14                    # Float
b = True                    # Boolean
s = "Python"               # String
print(f"2) Variables: int={i}, float={d}, bool={b}, str={s}\n")

# 3. Control Flow
print("3) Control Flow")
if i % 2 == 0:
    print("  Even")
else:
    print("  Odd")

for x in range(3):
    print(f"  for loop: {x}")

# 4. Functions and Arguments
def add(a, b):
    return a + b

print("\n4) Functions")
print(f"  add(3, 4) = {add(3, 4)}")

# 5. Classes and Objects
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(f"{self.name} makes a sound")

class Dog(Animal):
    def speak(self):
        print(f"{self.name} barks")

print("\n5) Classes and Inheritance")
a = Animal("Generic")
d = Dog("Fido")
a.speak()
d.speak()

# 6. Lists and List Comprehensions
nums = [1, 2, 3, 4]
squares = [x**2 for x in nums]  # List comprehension
print("\n6) Lists")
print(f"  Original: {nums}")
print(f"  Squares: {squares}")

# 7. Dictionaries and Loops
dict_sample = {"a": 1, "b": 2}
print("\n7) Dictionaries")
for key, val in dict_sample.items():
    print(f"  {key} => {val}")

# 8. Exception Handling
print("\n8) Exception Handling")
try:
    x = 1 / 0
except ZeroDivisionError as e:
    print(f"  Caught error: {e}")

# 9. Lambda Functions
print("\n9) Lambda Functions")
square = lambda x: x * x
print(f"  square(5) = {square(5)}")

# 10. File I/O
print("\n10) File I/O")
with open("sample.txt", "w") as f:
    f.write("Hello File!\n")

with open("sample.txt", "r") as f:
    content = f.read()
    print(f"  File Content: {content.strip()}")

# 11. Modules and Imports
print("\n11) Modules and Imports")
import math
print(f"  sqrt(16) = {math.sqrt(16)}")

# 12. List, Set, Dict Comprehensions
print("\n12) Comprehensions")
nums = [1, 2, 3]
print(f"  Set: {{x*2 for x in nums}} = { {x*2 for x in nums} }")
print(f"  Dict: {{x: x**2 for x in nums}} = { {x: x**2 for x in nums} }")

# 13. Decorators
def logger(func):
    def wrapper(*args, **kwargs):
        print(f"  Calling {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

def greet(name):
    print(f"  Hello, {name}")

greet("Alice")

# 14. Generators
def count_up_to(n):
    i = 0
    while i < n:
        yield i
        i += 1

print("\n14) Generators")
for num in count_up_to(3):
    print(f"  Yielded: {num}")

# 15. Working with JSON
print("\n15) JSON")
import json
person = {"name": "Bob", "age": 25}
json_str = json.dumps(person)
print(f"  JSON String: {json_str}")
back_to_dict = json.loads(json_str)
print(f"  Parsed Back: {back_to_dict}")

# 16. Async/Await (Basics)
print("\n16) Async/Await")
import asyncio

async def say_hello():
    await asyncio.sleep(1)
    print("  Hello from async!")

asyncio.run(say_hello())


