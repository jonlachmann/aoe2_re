import subprocess,sys
F='Source/gfx/draw_area.cpp'
src=open(F).read()
sig='void TDrawArea::SetClipBounds_460740(int left, int top, int right, int bottom)\n{'
start=src.index(sig)
end=src.index('\n}\n',start)+3
orig=src

HEAD='''    ClipLeft = left;
    ClipTop = top;
    ClipRight = right;
    ClipBottom = bottom;
'''
DEL_A='''    if (field_CC != 0 && Height != field_CC->field_50) {
        delete field_CC;
        field_CC = 0;
    }
'''
DEL_B='''    if (field_CC != 0 && field_CC->field_50 != Height) {
        delete field_CC;
        field_CC = 0;
    }
'''
DEL_C='''    if (field_CC != 0) {
        if (field_CC->field_50 != Height) {
            delete field_CC;
            field_CC = 0;
        }
    }
'''
NEW_A='''    if (field_CC == 0)
        field_CC = new TClipSpan(Width, Height);
'''
NEW_B='''    if (!field_CC)
        field_CC = new TClipSpan(Width, Height);
'''
NEW_C='''    if (field_CC == 0) {
        TClipSpan* p = new TClipSpan(Width, Height);
        field_CC = p;
    }
'''
TAIL_A='''    field_CC->Begin_523060();
    field_CC->SetRect_522FF0(ClipLeft, ClipTop, ClipRight, ClipBottom);
'''
TAIL_P='''    field_CC->Begin_523060();
    field_CC->SetRect_522FF0(ClipLeft, ClipTop, ClipRight, ClipBottom);
'''
LOOP_A='''    for (int y = ClipTop; y <= ClipBottom; y++)
        field_CC->ClipSpan_5230F0(ClipLeft, ClipRight, y);
'''
LOOP_INC='''    for (int y = ClipTop; y <= ClipBottom; ++y)
        field_CC->ClipSpan_5230F0(ClipLeft, ClipRight, y);
'''
LOOP_WHILE='''    int y = ClipTop;
    while (y <= ClipBottom) {
        field_CC->ClipSpan_5230F0(ClipLeft, ClipRight, y);
        ++y;
    }
'''
LOOP_DO='''    int y = ClipTop;
    if (y <= ClipBottom) {
        do {
            field_CC->ClipSpan_5230F0(ClipLeft, ClipRight, y);
            ++y;
        } while (y <= ClipBottom);
    }
'''
END='''    field_D0 = field_CC;
'''
V={
 'a': HEAD+DEL_A+NEW_A+TAIL_A+LOOP_A+END,
 'b': HEAD+DEL_B+NEW_A+TAIL_A+LOOP_A+END,
 'c': HEAD+DEL_B+NEW_A+TAIL_A+LOOP_INC+END,
 'd': HEAD+DEL_B+NEW_B+TAIL_A+LOOP_INC+END,
 'e': HEAD+DEL_B+NEW_A+TAIL_A+LOOP_WHILE+END,
 'f': HEAD+DEL_B+NEW_A+TAIL_A+LOOP_DO+END,
 'g': HEAD+DEL_C+NEW_A+TAIL_A+LOOP_INC+END,
 'h': HEAD+DEL_B+NEW_C+TAIL_A+LOOP_INC+END,
}
for k in (sys.argv[1:] or sorted(V)):
    open(F,'w').write(src[:start]+sig+V[k]+'\n}\n'+src[end:])
    r=subprocess.run(['./venv/bin/python','Scripts/match.py',F],capture_output=True,text=True)
    out=r.stdout
    m=[l for l in out.splitlines() if '0x460740' in l]
    print(k,m, 'misses', out.count('  ! '))
open(F,'w').write(orig)
