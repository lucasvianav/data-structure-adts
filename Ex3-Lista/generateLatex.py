files = [ 1, 2, 23, 3, 5, 6, 21, 7, 9, 10, 28, 12, 14, 15, 16, 18, 19, 20, 13 ]

f = open("./test-cases/latex.txt", "w")

index = 1

for k in files:
    i = str(index).zfill(2)
    k = str(k).zfill(2)
    print(" [*] %s -- %s --" % (i,k))

    fIn = open("./test-cases/" + k + ".in", "r")
    fOut = open("./test-cases/" + k + ".out", "r")

    inp = []
    out = []
    for line in fIn: inp.append(line.rstrip())
    for line in fOut: out.append(line.rstrip())

    fIn.close()
    fOut.close()

    bigger = max(len(inp),len(out))
    smaller = min(len(inp),len(out))
    isEqual = bigger == smaller

    f.write("\\begin{tabular}{p{0.5\\textwidth}p{0.5\\textwidth}}\n")
    f.write("\\textbf{" + i + ".in}\n&\n\\textbf{" + i + ".out}\\\\\n")
    for j in range(smaller): f.write(inp[j] + "\n&" + out[j] + "\\\\\n")

    if bigger == len(inp) and not isEqual: 
        for j in range(smaller,bigger): f.write(inp[j] + "\\\\\n")
    elif bigger == len(out) and not isEqual:
        for j in range(smaller,bigger): f.write("&" + out[j] + "\\\\\n")

    f.write("\\\\\n\\end{tabular}\n\n")

    print(" [*] %s -- %s ok\n" % (i,k))

    index+=1

f.close()