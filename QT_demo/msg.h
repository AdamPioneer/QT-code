// 消息队列结构
struct msg_form {
        long mtype;
        char mtext;
};

int create_msg(void);
int read_msg(int msqid, struct msg_form *msg);
int write_msg(int msqid);
//int write_msg(int msqid, struct msg_form *msg);
int delete_msg(int msqid);
