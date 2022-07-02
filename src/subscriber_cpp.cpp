#include "ros/ros.h" //ROSをc++で使えるようにする
#include "std_msgs/String.h"
#include "topic_sample_cpp/message_file.h" //"パッケージ名/拡張子なしmsgファイル名.h"

class Subscriber{ //サブスクライバのクラス
    public: //publicメンバとして関数を定義
        Subscriber();
        void callback(const topic_sample_cpp::message_file::ConstPtr &msg); //（パッケージ名::拡張子なしmsgファイル名::ConstPtr）
    private: //privateメンバとして変数を定義
        ros::NodeHandle nh; //ROSと通信するためのノードハンドルの作成
        ros::Subscriber subscriber; //サブスクライバの定義
};

Subscriber::Subscriber(){
    subscriber = nh.subscribe("topic_name", 1000, &Subscriber::callback, this); //サブスクライバのインスタンス生成
}

void Subscriber::callback(const topic_sample_cpp::message_file::ConstPtr &msg){ //メッセージを受信すると呼び出されるコールバック関数の定義    
    ROS_INFO("%d", msg->count); //ログの表示
}

int main(int argc, char **argv){ //メイン関数
    ros::init(argc, argv, "subscriber_node"); //ノードの初期化
    Subscriber sub; //クラスのインスタンス生成
    ros::spin(); //終了防止
    return 0; //終了
}