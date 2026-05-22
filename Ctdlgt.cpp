#include <iostream>
#include <string>
using namespace std;

// Cấu trúc dữ liệu sản phẩm
struct Product {
    int id;
    string mahh;      // Mã hàng hóa
    string tenhh;     // Tên hàng hóa
    double gia;       // Giá
    string donvi;     // Đơn vị tính
    string category;  // Danh mục
};

// Node của danh sách móc nối (theo mẫu của cô)
struct Node {
    Product infor;    // Dữ liệu (theo cách gọi của cô)
    Node* next;       // Con trỏ tới node kế
};

typedef Node* TRO;    // TRO là con trỏ Node (theo đúng mẫu cô dạy)

// ----- CÁC HÀM CƠ BẢN (theo mẫu của cô) -----

// Kiểm tra danh sách rỗng
bool empty(TRO L) {
    return L == NULL;
}

// Thêm vào cuối danh sách (add của cô)
void add(TRO& L, Product elem) {
    TRO P = new Node;
    P->infor = elem;
    P->next = NULL;
    if (empty(L)) {
        L = P;
    } else {
        TRO Q = L;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

// In danh sách sản phẩm
void inDanhSach(TRO L) {
    if (empty(L)) {
        cout << "Danh sach rong.\n";
        return;
    }
    int idx = 1;
    TRO Q = L;
    while (Q != NULL) {
        cout << idx << ". ID: " << Q->infor.id
             << ", MaHH: " << Q->infor.mahh
             << ", TenHH: " << Q->infor.tenhh
             << ", Gia: " << Q->infor.gia
             << ", Don vi: " << Q->infor.donvi
             << ", Category: " << Q->infor.category << endl;
        Q = Q->next;
        idx++;
    }
    cout << "--------------------------------------\n";
}

// ----- CÁC HÀM XỬ LÝ YÊU CẦU CỤ THỂ -----

// 1. Xóa phần tử thứ 4 trong danh sách
void xoaPhanTuThu4(TRO& L) {
    if (empty(L)) {
        cout << ">> Danh sach rong, khong the xoa.\n";
        return;
    }

    TRO prev = NULL, curr = L;
    int pos = 1;
    while (curr != NULL && pos < 4) {
        prev = curr;
        curr = curr->next;
        pos++;
    }

    if (curr == NULL) {
        cout << ">> Khong co phan tu thu 4.\n";
        return;
    }

    // Xóa curr
    if (prev == NULL) {       // curr là đầu danh sách
        L = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    cout << ">> Da xoa phan tu thu 4.\n";
}

// 2. Xóa tất cả phần tử có mahh = "123"
void xoaMahh123(TRO& L) {
    if (empty(L)) return;

    TRO prev = NULL, curr = L;
    while (curr != NULL) {
        if (curr->infor.mahh == "123") {
            if (prev == NULL) {   // xóa đầu
                L = curr->next;
                delete curr;
                curr = L;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            cout << ">> Da xoa mot phan tu mahh = 123.\n";
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// 3. Xóa tất cả phần tử có tenhh = "but chi"
void xoaTenhhButChi(TRO& L) {
    if (empty(L)) return;

    TRO prev = NULL, curr = L;
    while (curr != NULL) {
        if (curr->infor.tenhh == "but chi") {
            if (prev == NULL) {
                L = curr->next;
                delete curr;
                curr = L;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            cout << ">> Da xoa mot phan tu tenhh = but chi.\n";
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// 4. Chèn sản phẩm mới vào trước vị trí số 3
void chenTruocViTri3(TRO& L, Product sp) {
    TRO newNode = new Node;
    newNode->infor = sp;
    newNode->next = NULL;

    // Trường hợp chèn vào đầu (danh sách rỗng hoặc vị trí 1)
    if (empty(L) || 3 <= 1) {
        newNode->next = L;
        L = newNode;
        cout << ">> Da chen vao dau danh sach.\n";
        return;
    }

    TRO prev = NULL, curr = L;
    int pos = 1;
    while (curr != NULL && pos < 3) {
        prev = curr;
        curr = curr->next;
        pos++;
    }

    // prev là node thứ 2, curr là node thứ 3 (nếu có)
    if (prev != NULL) {
        newNode->next = curr;
        prev->next = newNode;
        cout << ">> Da chen vao truoc vi tri 3.\n";
    } else {
        add(L, sp); // thêm cuối nếu không đủ 2 phần tử
        cout << ">> Chen vao cuoi (vi tri 3 vuot qua danh sach).\n";
    }
}

// 5. Chèn sản phẩm mới vào trước node có mahh = "123"
void chenTruocMahh123(TRO& L, Product sp) {
    TRO newNode = new Node;
    newNode->infor = sp;
    newNode->next = NULL;

    if (empty(L)) {
        L = newNode;
        cout << ">> Danh sach rong, da chen vao dau.\n";
        return;
    }

    TRO prev = NULL, curr = L;
    while (curr != NULL && curr->infor.mahh != "123") {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {   // Không tìm thấy -> thêm cuối
        add(L, sp);
        cout << ">> Khong tim thay mahh 123, da them vao cuoi.\n";
    } else {
        newNode->next = curr;
        if (prev == NULL) { // chèn trước đầu
            L = newNode;
        } else {
            prev->next = newNode;
        }
        cout << ">> Da chen truoc node mahh = 123.\n";
    }
}

// 6. Chèn sản phẩm mới vào trước node có tenhh = "but chi"
void chenTruocTenhhButChi(TRO& L, Product sp) {
    TRO newNode = new Node;
    newNode->infor = sp;
    newNode->next = NULL;

    if (empty(L)) {
        L = newNode;
        cout << ">> Danh sach rong, da chen vao dau.\n";
        return;
    }

    TRO prev = NULL, curr = L;
    while (curr != NULL && curr->infor.tenhh != "but chi") {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        add(L, sp);
        cout << ">> Khong tim thay tenhh 'but chi', da them vao cuoi.\n";
    } else {
        newNode->next = curr;
        if (prev == NULL) {
            L = newNode;
        } else {
            prev->next = newNode;
        }
        cout << ">> Da chen truoc node tenhh = but chi.\n";
    }
}

// Giải phóng bộ nhớ
void clearList(TRO& L) {
    while (!empty(L)) {
        TRO tmp = L;
        L = L->next;
        delete tmp;
    }
}

// ==================== HÀM MAIN ====================
int main() {
    TRO danhSach = NULL;

    // Tạo danh sách mẫu 5 sản phẩm
    Product sp1 = {1, "001", "but chi", 5000, "cai", "van phong pham"};
    Product sp2 = {2, "123", "vo ghi", 10000, "quyen", "van phong pham"};
    Product sp3 = {3, "002", "thuoc ke", 7000, "cai", "van phong pham"};
    Product sp4 = {4, "003", "but muc", 8000, "cai", "van phong pham"};
    Product sp5 = {5, "004", "tay", 3000, "cai", "van phong pham"};

    add(danhSach, sp1);
    add(danhSach, sp2);
    add(danhSach, sp3);
    add(danhSach, sp4);
    add(danhSach, sp5);

    cout << "======== DANH SACH BAN DAU ========\n";
    inDanhSach(danhSach);

    // 1. Xóa phần tử thứ 4
    xoaPhanTuThu4(danhSach);
    cout << "Sau khi xoa phan tu thu 4:\n";
    inDanhSach(danhSach);

    // 2. Xóa phần tử có mahh = 123
    xoaMahh123(danhSach);
    cout << "Sau khi xoa mahh = 123:\n";
    inDanhSach(danhSach);

    // 3. Xóa phần tử có tenhh = but chi
    xoaTenhhButChi(danhSach);
    cout << "Sau khi xoa tenhh = but chi:\n";
    inDanhSach(danhSach);

    // 4. Chèn vào trước phần tử số 3
    Product new1 = {10, "NEW01", "bang den", 15000, "cai", "thiet bi"};
    chenTruocViTri3(danhSach, new1);
    cout << "Sau khi chen truoc vi tri 3:\n";
    inDanhSach(danhSach);

    // 5. Chèn vào trước mahh 123 (lúc này mahh 123 đã bị xóa -> sẽ thêm cuối)
    Product new2 = {11, "NEW02", "giay A4", 30000, "ram", "van phong"};
    chenTruocMahh123(danhSach, new2);
    cout << "Sau khi chen truoc mahh 123 (khong co):\n";
    inDanhSach(danhSach);

    // Thêm lại một node mahh 123 để kiểm tra chèn trước
    Product sp123 = {20, "123", "vo caro", 12000, "quyen", "van phong"};
    add(danhSach, sp123);
    cout << "Da them lai node mahh 123:\n";
    inDanhSach(danhSach);

    Product new3 = {12, "NEW03", "but long", 8000, "cai", "van phong"};
    chenTruocMahh123(danhSach, new3);
    cout << "Sau khi chen truoc mahh 123 (co ton tai):\n";
    inDanhSach(danhSach);

    // 6. Chèn vào trước tenhh "but chi" (đã bị xóa -> thêm cuối)
    Product new4 = {13, "NEW04", "but chi 2", 6000, "cai", "van phong"};
    chenTruocTenhhButChi(danhSach, new4);
    cout << "Sau khi chen truoc tenhh 'but chi' (khong co):\n";
    inDanhSach(danhSach);

    clearList(danhSach);
    return 0;
}
