# ESP32
esp32でいろいろ工作するのでgitに上げてみた。
基本的にArduinoIDEでコードを書いていきます。

#Lchika
Lチカするだけ

#AutoMamakitabutton
・説明
  人に見られたくない作業をしているときにいきなり人が部屋に入って来ても大丈夫な状態にできるシステム。
  [注意]PythonとそのフレームワークのFlaskの環境が必要です。
        各パッケージマネージャでPython3とpipをいれてから、この記事などを参考にFlaskを入れてください。
        https://qiita.com/zaburo/items/5091041a5afb2a7dffc8
・仕組み
  予めwebapiのlock_api.pyを走らせておいたら、
  超音波距離センサー(HC-SR04)でドアが開いたことを感知したら、GETを送ってPCにロックがかかります。
  また、自分はi3wmを使っているので実行するコマンドが"i3lock"になっています。
