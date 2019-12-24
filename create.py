import os
val=input("enter the number");
text=input("enter the problem");
s=str(val);
f= open(s+".in","w+")
f.close();
f= open(s+".out","w+")
f.close();
f= open(s+".py","w+")
f.close();
f= open(s+".cpp","w+")
f.close();
f= open(s+".md","w+")
f.write("# "+text);
f.write("\n\n");
f.write("### Input:\n");
f.write("@Input@\n");
f.write("### Output:\n");
f.write("@Output@\n");
f.write("\n\n");
f.write("## Possible Questions to ask:\n");
f.write("\n\n");
f.write("## Explanation:\n");
f.write("\n\n");
f.write("@CPP@\n");
f.write("@PY3@\n");

f.close();