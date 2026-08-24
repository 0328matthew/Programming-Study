import datetime

now = datetime.datetime.now()

dialogue = input("간단한 문장을 입력 해 보세요: ")

if(dialogue == "안녕") :
    print("안녕")
elif(dialogue == "안녕하세요.") :
    print("안녕하세요.")
elif(dialogue == "지금 몇 시야?") :
    time_24 = now.strftime("%H시")
    print(print(f"지금은 {time_24}입니다."))
else :
    print(dialogue)

input("종료하려면 Enter 키를 누르세요...")

