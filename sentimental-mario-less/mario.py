# TODO

def main():
    height = get_height()


    for i in range(height):
        for j in range(height - (i+1)):
            print(" ", end = "")
        for k in range(i+1):
            print("#", end = "")

        print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
        except ValueError:
            print("That's not an integer!")
        else:
            if n > 0 and n != 9:
                return n

main()




# def main():
#     height = get_height()
#     for i in range(height):
#         for j in range(height - i):
#             print("#", end="")
#         print()

# def get_height():
#     while True:
#         try:
#             n = int(input("Height: "))
#         except ValueError:
#             print("That's not an integer!")
#         else:
#             if n > 0:
#                 return n

# main()