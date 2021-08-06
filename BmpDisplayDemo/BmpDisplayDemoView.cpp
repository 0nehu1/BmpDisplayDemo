
// BmpDisplayDemoView.cpp: CBmpDisplayDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BmpDisplayDemo.h"
#endif

#include "BmpDisplayDemoDoc.h"
#include "BmpDisplayDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpDisplayDemoView

IMPLEMENT_DYNCREATE(CBmpDisplayDemoView, CView)

BEGIN_MESSAGE_MAP(CBmpDisplayDemoView, CView)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBmpDisplayDemoView 생성/소멸

CBmpDisplayDemoView::CBmpDisplayDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBmpDisplayDemoView::~CBmpDisplayDemoView()
{
}

BOOL CBmpDisplayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBmpDisplayDemoView 그리기

void CBmpDisplayDemoView::OnDraw(CDC* /*pDC*/)
{
	CBmpDisplayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBmpDisplayDemoView 진단

#ifdef _DEBUG
void CBmpDisplayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpDisplayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpDisplayDemoDoc* CBmpDisplayDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpDisplayDemoDoc)));
	return (CBmpDisplayDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpDisplayDemoView 메시지 처리기


void CBmpDisplayDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.

	CDC MemDC;
	BITMAP bmpInfo;
	//화면 DC와 호환되는 메모리 DC를 생성한다.
	MemDC.CreateCompatibleDC(&dc);
	//비트맵 리소스를 로딩한다.
	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmapW(IDB_BITMAP_IU);
	//로딩된 비트맵의 정보를 알아본다.
	bmp.GetBitmap(&bmpInfo);
	//메모리 DC에 선택한다.
	pOldBmp = MemDC.SelectObject(&bmp);
	//메모리 DC에 들어있는 비트맵을 화면 DC로 복사하여 출력한다.
	//dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight,&MemDC,0,0,SRCCOPY);
	dc.BitBlt(100, 100, 250, 400, &MemDC, 250, 100, SRCCOPY);
	dc.BitBlt(200, 200, 150, 300, &MemDC, 350, 200, NOTSRCCOPY);
	//dc.StretchBlt(200, 200, // 출력될 좌표
	//	250 * 2, 300 * 2,// 폭과 녹피을 두배 확대
	//	&MemDC, 350, 200, //원본 이미지 좌표
	//	250, 300, // 원본 이미지의 폭과 높이
	//	NOTSRCCOPY);	//SRCCOPY ,SRCAND, NOTSRCCOPY, DSTINVERT
	MemDC.SelectObject(pOldBmp);


}
