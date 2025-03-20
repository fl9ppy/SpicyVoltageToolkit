# 🛠️ CTF CLI Tool - The Ultimate CTF Companion

CTF CLI Tool is a **high-performance, menu-driven** command-line tool designed for **Capture The Flag (CTF) competitions**.  
It automates **reconnaissance, exploitation, cryptography, brute-force attacks, OSINT, and privilege escalation** tasks, while also allowing users to execute custom scripts.

![CTF CLI Tool Demo](https://via.placeholder.com/800x400?text=CTF+CLI+Tool+Demo)

---

## **📌 Features**
✅ **Reconnaissance & Enumeration** - Automated Nmap scanning & Gobuster subdomain enumeration.  
✅ **Web Exploitation** - Automated SQL injection testing with SQLmap.  
✅ **Privilege Escalation** - Linux & Windows privilege escalation checks using LinPEAS & WinPEAS.  
✅ **Cryptography Tools** - Base64, ROT13, Hash Identifier.  
✅ **Brute-Force Attacks** - Hydra (SSH, FTP, HTTP), John the Ripper, Hashcat.  
✅ **OSINT Tools** - Amass, theHarvester, Sublist3r.  
✅ **Custom Script Execution** - Store & run Python, Bash, Perl, and custom scripts.  

---

## **📌 Installation & Setup**
### **🔹 1. Clone the Repository**
```sh
git clone https://github.com/your-username/ctf-cli-tool.git
cd ctf-cli-tool
```

### **🔹 2. Install Dependencies**
```sh
sudo apt update && sudo apt install -y nmap sqlmap gobuster steghide binwalk john exiftool hydra hashcat linpeas winpeas rot13 hash-identifier amass theharvester sublist3r
```

### **🔹 3. Compile the Project**
```sh
make
```
or manually:
```sh
g++ -o ctftool main.cpp Menus/*.cpp -I Headers -std=c++17
```

### **🔹 4. Run the Tool**
```sh
./ctftool
```

---

## **📌 Usage**
### **1️⃣ Main Menu**
```txt
====================================
     CTF AUTOMATION TOOL (ALPHA)   
====================================

1. Recon & Enumeration
2. Web Exploitation
3. Privilege Escalation
4. Cryptography Tools
5. Brute Force Attacks
6. OSINT Tools
7. Script Manager
8. Exit
```

---

### **2️⃣ Recon & Enumeration**
- **Nmap Scan:** `nmap -A target-ip`  
- **Subdomain Enumeration:** `gobuster dns -d target.com -w wordlist.txt`

Example:
```sh
1
Enter target IP/Domain: scanme.nmap.org
```

---

### **3️⃣ Web Exploitation**
- **SQL Injection:** `sqlmap -u target-url --dbs`

Example:
```sh
2
Enter target URL: http://testphp.vulnweb.com/listproducts.php?cat=1
```

---

### **4️⃣ Privilege Escalation**
- **Linux PE:** Runs LinPEAS automatically.  
- **Windows PE:** Runs WinPEAS automatically.  

Example:
```sh
3
```

---

### **5️⃣ Cryptography Tools**
- **Base64 Encode/Decode**
- **ROT13 Encode/Decode**
- **Hash Identifier**

Example:
```sh
4
1
Enter text: hello
```

---

### **6️⃣ Brute-Force Attacks**
- **Hydra for SSH, FTP, HTTP brute-forcing**
- **John the Ripper for offline hash cracking**
- **Hashcat for GPU-powered cracking**

Example:
```sh
5
1
Enter target IP: 192.168.1.1
Enter service: ssh
Enter wordlist path: /usr/share/wordlists/rockyou.txt
```

---

### **7️⃣ OSINT Tools**
- **Amass:** `amass enum -d target.com`
- **theHarvester:** `theHarvester -d target.com -b all`
- **Sublist3r:** `sublist3r -d target.com`

Example:
```sh
6
1
Enter target domain: example.com
```

---

### **8️⃣ Script Manager**
- **List scripts**
- **Execute scripts**
- **Add new scripts**

Example:
```sh
7
1
```

---

## **📌 Adding Custom Scripts**
You can **add, list, and execute scripts** from the `Scripts/` directory.

### **🔹 1. Add a New Script**
```sh
7
3
Enter new script name (e.g., exploit.py): myscript.py
Enter script content:
print("Hello from myscript!")
```
Press **Ctrl+D** to save and exit.

### **🔹 2. List Available Scripts**
```sh
7
1
```

### **🔹 3. Execute a Script**
```sh
7
2
Enter script name: myscript.py
```

---

## **📌 Contributing**
Contributions are welcome! Feel free to open issues and pull requests. If you'd like to add more features or improve the project, follow these steps:
1. Fork the repository.
2. Create a feature branch.
3. Commit your changes.
4. Push the branch and submit a pull request.

---

## **📌 License**
This project is licensed under the MIT License.
