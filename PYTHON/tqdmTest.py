from tqdm import tqdm
import time



def tqdm_test(a):
    t=tqdm(a)
    for i in t:
        pass
        # time.sleep(1)
        # print(i)


def main():
    a=['1','2','3','4','5','6','7777','8887','qwe']
    tqdm_test(a)

if __name__=='__main__':
    main()