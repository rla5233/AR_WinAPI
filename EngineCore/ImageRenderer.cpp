#include "ImageRenderer.h"
#include "EngineCore.h"
#include "Level.h"
#include "Actor.h"

UImageRenderer::UImageRenderer()
{
}

UImageRenderer::~UImageRenderer()
{
}

void UImageRenderer::SetOrder(int _Order)
{
	AActor* Owner = GetOwner();
	ULevel* Level = Owner->GetWorld();

	std::map<int, std::list<UImageRenderer*>>& Renderers = Level->Renderers;
	// 렌더링 순서를 바꾸기전 리스트 어딘가 속해있으면 삭제
	Renderers[GetOrder()].remove(this);

	// 렌더링 순서를 바꾸고 리스트에 추가
	UTickObject::SetOrder(_Order);
	Renderers[GetOrder()].push_back(this);
}

void UImageRenderer::Render(float _DeltaTime)
{
	HDC WindowDC = GEngine->MainWindow.GetWindowDC();
	FTransform ThisTrans = GetTransform();
	FTransform OwnerTrans = GetOwner()->GetTransform();

	// 컴포넌트의 위치는 부모에게서 상대적이기 때문에.
	// 부모의 위치를 더해줘야 한다.
	ThisTrans.AddPosition(OwnerTrans.GetPosition());

	Rectangle(WindowDC, ThisTrans.iLeft(), ThisTrans.iTop(), ThisTrans.iRight(), ThisTrans.iBottom());
}

void UImageRenderer::BeginPlay()
{}
