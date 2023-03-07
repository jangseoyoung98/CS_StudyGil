
from dataclasses import dataclass

#### Algorithm to Linked List ####
## input : X..?
## output : 링크드리스트
## conditions : 노드(구조체) / 링크드리스트(클래스) / 삽입, 삭제, 조회, 출력 함수

## node : dataclass 사용 (파이썬3.7~)
# 1. @dataclass으로 노드를 구조체 형태로 정의한다.
# 2. 변수로 data와 next를 가진다.
@dataclass
class Node:
    data: int
    next: Node

    

## LinkedList
class LinkedList:
    def __init__() -> None:


## func1 : InsertFirst()
# input : data
# output : X (LinkedList 첫 자리에 노드가 삽입됨)
# 1. 삽입할 노드를 만들고 인자로 들어온 데이터를 저장한다.
# 2. 헤드값을 가져온다. 헤드값이 없다면 새로만든 노드를 헤드로 지정한다.
# 3. 헤드값이 있다면 새로만든 노드의 next를 헤드 값으로 


## func2 : Delete()

## func3 : Search()
## func4 : Print()

##################################
